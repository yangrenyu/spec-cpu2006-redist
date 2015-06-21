/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 1999-2003 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Id: XMLReader.cpp,v 1.19 2004/01/29 11:46:30 cargilld Exp $
 */

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/internal/XMLReader.hpp>
#include <xercesc/util/BitOps.hpp>
#include <xercesc/util/BinInputStream.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/RuntimeException.hpp>
#include <xercesc/util/TranscodingException.hpp>
#include <xercesc/util/TransService.hpp>
#include <xercesc/util/XMLEBCDICTranscoder.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/Janitor.hpp>


XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  XMLReader: Query Methods
// ---------------------------------------------------------------------------
//  Checks whether all of the chars in the passed buffer are whitespace or
//  not. Breaks out on the first non-whitespace.
//
bool XMLReader::isAllSpaces(const   XMLCh* const    toCheck
                            , const unsigned int    count)
{
    const XMLCh* curCh = toCheck;
    const XMLCh* endPtr = toCheck + count;
    while (curCh < endPtr)
    {
        if (!(fgCharCharsTable[*curCh++] & gWhitespaceCharMask))
            return false;
    }
    return true;
}


//
//  Checks whether at least one of the chars in the passed buffer are whitespace or
//  not.
//
bool XMLReader::containsWhiteSpace(const   XMLCh* const    toCheck
                            , const unsigned int    count)
{
    const XMLCh* curCh = toCheck;
    const XMLCh* endPtr = toCheck + count;
    while (curCh < endPtr)
    {
        if (fgCharCharsTable[*curCh++] & gWhitespaceCharMask)
            return true;
    }
    return false;
}

//
//  This one is not called terribly often, so call the XMLChar utility
//
bool XMLReader::isPublicIdChar(const XMLCh toCheck)
{
    if (fXMLVersion == XMLV1_1)
        return XMLChar1_1::isPublicIdChar(toCheck);
    else
        return XMLChar1_0::isPublicIdChar(toCheck);
}

// ---------------------------------------------------------------------------
//  XMLReader: Constructors and Destructor
// ---------------------------------------------------------------------------
XMLReader::XMLReader(const  XMLCh* const          pubId
                    , const XMLCh* const          sysId
                    ,       BinInputStream* const streamToAdopt
                    , const RefFrom               from
                    , const Types                 type
                    , const Sources               source
                    , const bool                  throwAtEnd
                    , const bool                  calculateSrcOfs
                    , const XMLVersion            version
                    ,       MemoryManager* const  manager) :
    fCharIndex(0)
    , fCharsAvail(0)
    , fCurCol(1)
    , fCurLine(1)
    , fEncodingStr(0)
    , fForcedEncoding(false)
    , fNoMore(false)
    , fPublicId(XMLString::replicate(pubId, manager))
    , fRawBufIndex(0)
    , fRawBytesAvail(0)
    , fReaderNum(0xFFFFFFFF)
    , fRefFrom(from)
    , fSentTrailingSpace(false)
    , fSource(source)
    , fSrcOfsBase(0)
    , fSrcOfsSupported(false)
    , fCalculateSrcOfs(calculateSrcOfs)    
    , fSystemId(XMLString::replicate(sysId, manager))
    , fStream(streamToAdopt)
    , fSwapped(false)
    , fThrowAtEnd(throwAtEnd)
    , fTranscoder(0)
    , fType(type)
    , fMemoryManager(manager)
{
    setXMLVersion(version);

    // Do an initial load of raw bytes
    refreshRawBuffer();

    // Ask the transcoding service if it supports src offset info
    fSrcOfsSupported = XMLPlatformUtils::fgTransService->supportsSrcOfs();

    //
    //  Use the recognizer class to get a basic sense of what family of
    //  encodings this file is in. We'll start off with a reader of that
    //  type, and update it later if needed when we read the XMLDecl line.
    //
    fEncoding = XMLRecognizer::basicEncodingProbe(fRawByteBuf, fRawBytesAvail);

    #if defined(XERCES_DEBUG)
    if ((fEncoding < XMLRecognizer::Encodings_Min)
    ||  (fEncoding > XMLRecognizer::Encodings_Max))
    {
        ThrowXMLwithMemMgr(RuntimeException, XMLExcepts::Reader_BadAutoEncoding, fMemoryManager);
    }
    #endif

    fEncodingStr = XMLString::replicate(XMLRecognizer::nameForEncoding(fEncoding, fMemoryManager), fMemoryManager);

    // Check whether the fSwapped flag should be set or not
    checkForSwapped();

    //
    //  This will check to see if the first line is an XMLDecl and, if
    //  so, decode that first line manually one character at a time. This
    //  leaves enough characters in the buffer that the high level code
    //  can get through the Decl and call us back with the real encoding.
    //
    doInitDecode();

    //
    //  NOTE: We won't create a transcoder until we either get a call to
    //  setEncoding() or we get a call to refreshCharBuffer() and no
    //  transcoder has been set yet.
    //
}


XMLReader::XMLReader(const  XMLCh* const          pubId
                    , const XMLCh* const          sysId
                    ,       BinInputStream* const streamToAdopt
                    , const XMLCh* const          encodingStr
                    , const RefFrom               from
                    , const Types                 type
                    , const Sources               source
                    , const bool                  throwAtEnd
                    , const bool                  calculateSrcOfs
                    , const XMLVersion            version
                    ,       MemoryManager* const  manager) :
    fCharIndex(0)
    , fCharsAvail(0)
    , fCurCol(1)
    , fCurLine(1)
    , fEncoding(XMLRecognizer::UTF_8)
    , fEncodingStr(0)
    , fForcedEncoding(true)
    , fNoMore(false)
    , fPublicId(XMLString::replicate(pubId, manager))
    , fRawBufIndex(0)
    , fRawBytesAvail(0)
    , fReaderNum(0xFFFFFFFF)
    , fRefFrom(from)
    , fSentTrailingSpace(false)
    , fSource(source)
    , fSrcOfsBase(0)
    , fSrcOfsSupported(false)
    , fCalculateSrcOfs(calculateSrcOfs)    
    , fSystemId(XMLString::replicate(sysId, manager))
    , fStream(streamToAdopt)
    , fSwapped(false)
    , fThrowAtEnd(throwAtEnd)
    , fTranscoder(0)
    , fType(type)
    , fMemoryManager(manager)
{
    setXMLVersion(version);

    // Do an initial load of raw bytes
    refreshRawBuffer();

    // Copy the encoding string to our member
    fEncodingStr = XMLString::replicate(encodingStr, fMemoryManager);
    XMLString::upperCase(fEncodingStr);

    // Ask the transcoding service if it supports src offset info
    fSrcOfsSupported = XMLPlatformUtils::fgTransService->supportsSrcOfs();

    //
    //  Map the passed encoding name to one of our enums. If it does not
    //  match one of the intrinsic encodings, it will come back 'other',
    //  which tells us to create a transcoder based reader.
    //
    fEncoding = XMLRecognizer::encodingForName(fEncodingStr);

    // Check whether the fSwapped flag should be set or not
    checkForSwapped();

    //
    //  Create a transcoder for the encoding. Since the encoding has been
    //  forced, this will be the one we will use, period.
    //
    XMLTransService::Codes failReason;
    if (fEncoding == XMLRecognizer::OtherEncoding)
    {
        //
        //  fEncodingStr not  pre-recognized, use it
        //  directly for transcoder
        //
        fTranscoder = XMLPlatformUtils::fgTransService->makeNewTranscoderFor
        (
            fEncodingStr
            , failReason
            , kCharBufSize
            , fMemoryManager
        );
    }
     else
    {
        //
        //  Use the recognized fEncoding to create the transcoder
        //
        fTranscoder = XMLPlatformUtils::fgTransService->makeNewTranscoderFor
        (
            fEncoding
            , failReason
            , kCharBufSize
            , fMemoryManager
        );

    }

    if (!fTranscoder)
    {
        ThrowXMLwithMemMgr1
        (
            TranscodingException
            , XMLExcepts::Trans_CantCreateCvtrFor
            , fEncodingStr
            , fMemoryManager
        );
    }

    //
    //  Note that, unlike above, we do not do an initial decode of the
    //  first line. We take the caller's word that the encoding is correct
    //  and just assume that the first bulk decode (kicked off by the first
    //  get of a character) will work.
    //
    //  So we do here the slipping in of the leading space if required.
    //
    if ((fType == Type_PE) && (fRefFrom == RefFrom_NonLiteral))
    {
        // This represents no data from the source
        fCharSizeBuf[fCharsAvail] = 0;
        fCharBuf[fCharsAvail++] = chSpace;
    }
}


XMLReader::XMLReader(const  XMLCh* const          pubId
                    , const XMLCh* const          sysId
                    ,       BinInputStream* const streamToAdopt
                    , XMLRecognizer::Encodings    encodingEnum
                    , const RefFrom               from
                    , const Types                 type
                    , const Sources               source
                    , const bool                  throwAtEnd
                    , const bool                  calculateSrcOfs
                    , const XMLVersion            version
                    ,       MemoryManager* const  manager) :
    fCharIndex(0)
    , fCharsAvail(0)
    , fCurCol(1)
    , fCurLine(1)
    , fEncoding(XMLRecognizer::UTF_8)
    , fEncodingStr(0)
    , fForcedEncoding(true)
    , fNoMore(false)
    , fPublicId(XMLString::replicate(pubId, manager))
    , fRawBufIndex(0)
    , fRawBytesAvail(0)
    , fReaderNum(0xFFFFFFFF)
    , fRefFrom(from)
    , fSentTrailingSpace(false)
    , fSource(source)
    , fSrcOfsBase(0)
    , fSrcOfsSupported(false)
    , fCalculateSrcOfs(calculateSrcOfs)    
    , fSystemId(XMLString::replicate(sysId, manager))
    , fStream(streamToAdopt)
    , fSwapped(false)
    , fThrowAtEnd(throwAtEnd)
    , fTranscoder(0)
    , fType(type)
    , fMemoryManager(manager)
{
    setXMLVersion(version);

    // Do an initial load of raw bytes
    refreshRawBuffer();

    // Ask the transcoding service if it supports src offset info
    fSrcOfsSupported = XMLPlatformUtils::fgTransService->supportsSrcOfs();

    //
    //  Use the passed encoding code
    //
    fEncoding = encodingEnum;
    fEncodingStr = XMLString::replicate(XMLRecognizer::nameForEncoding(fEncoding, fMemoryManager), fMemoryManager);

    // Check whether the fSwapped flag should be set or not
    checkForSwapped();

    //
    //  Create a transcoder for the encoding. Since the encoding has been
    //  forced, this will be the one we will use, period.
    //
    XMLTransService::Codes failReason;
    fTranscoder = XMLPlatformUtils::fgTransService->makeNewTranscoderFor
    (
        fEncoding
        , failReason
        , kCharBufSize
        , fMemoryManager
    );

    if (!fTranscoder)
    {
        ThrowXMLwithMemMgr1
        (
            TranscodingException
            , XMLExcepts::Trans_CantCreateCvtrFor
            , fEncodingStr
            , fMemoryManager
        );
    }

    //
    //  Note that, unlike above, we do not do an initial decode of the
    //  first line. We take the caller's word that the encoding is correct
    //  and just assume that the first bulk decode (kicked off by the first
    //  get of a character) will work.
    //
    //  So we do here the slipping in of the leading space if required.
    //
    if ((fType == Type_PE) && (fRefFrom == RefFrom_NonLiteral))
    {
        // This represents no data from the source
        fCharSizeBuf[fCharsAvail] = 0;
        fCharBuf[fCharsAvail++] = chSpace;
    }
}


XMLReader::~XMLReader()
{
    fMemoryManager->deallocate(fEncodingStr);
    fMemoryManager->deallocate(fPublicId);
    fMemoryManager->deallocate(fSystemId);
    delete fStream;
    delete fTranscoder;
}


// ---------------------------------------------------------------------------
//  XMLReader: Character buffer management methods
// ---------------------------------------------------------------------------
unsigned int XMLReader::getSrcOffset() const
{
    if (!fSrcOfsSupported || !fCalculateSrcOfs)
        ThrowXMLwithMemMgr(RuntimeException, XMLExcepts::Reader_SrcOfsNotSupported, fMemoryManager);

    //
    //  Take the current source offset and add in the sizes that we've
    //  eaten from the source so far.
    //
    unsigned int offset = fSrcOfsBase;
    for (unsigned int index = 0; index < fCharIndex; index++)
        offset += fCharSizeBuf[index];

    return offset;
}


bool XMLReader::refreshCharBuffer()
{
    // If the no more flag is set, then don't both doing anything
    if (fNoMore)
        return false;

    unsigned int startInd;

    // See if we have any existing chars.
    const unsigned int spareChars = fCharsAvail - fCharIndex;

    // If we are full, then don't do anything.
    if (spareChars == kCharBufSize)
        return true;

    //
    //  If no transcoder has been created yet, then we never saw the
    //  any encoding="" string and the encoding was not forced, so lets
    //  create one now. We know that it won't change now.
    //
    //  However, note that if we autosensed EBCDIC, then we have to
    //  consider it an error if we never got an encoding since we don't
    //  know what variant of EBCDIC it is.
    //
    if (!fTranscoder)
    {
        if (fEncoding == XMLRecognizer::EBCDIC)
            ThrowXMLwithMemMgr(RuntimeException, XMLExcepts::Reader_EncodingStrRequired, fMemoryManager);

        // Ask the transcoding service to make use a transcoder
        XMLTransService::Codes failReason;
        fTranscoder = XMLPlatformUtils::fgTransService->makeNewTranscoderFor
        (
            fEncodingStr
            , failReason
            , kCharBufSize
            , fMemoryManager
        );

        if (!fTranscoder)
        {
            ThrowXMLwithMemMgr1
            (
                TranscodingException
                , XMLExcepts::Trans_CantCreateCvtrFor
                , fEncodingStr
                , fMemoryManager
            );
        }
    }

    //
    //  Add the number of source bytes eaten so far to the base src
    //  offset member.
    //
    if (fCalculateSrcOfs) {
        for (startInd = 0; startInd < fCharIndex; startInd++)
            fSrcOfsBase += fCharSizeBuf[startInd];
    }

    //
    //  If there are spare chars, then move then down to the bottom. We
    //  have to move the char sizes down also.
    //
    startInd = 0;
    if (spareChars)
    {
        for (unsigned int index = fCharIndex; index < fCharsAvail; index++)
        {
            fCharBuf[startInd] = fCharBuf[index];
            fCharSizeBuf[startInd] = fCharSizeBuf[index];
            startInd++;
        }
    }

    //
    //  And then get more chars, starting after any spare chars that were
    //  left over from the last time.
    //
    fCharsAvail = xcodeMoreChars
    (
        &fCharBuf[startInd]
        , &fCharSizeBuf[startInd]
        , kCharBufSize - spareChars
    );

    // Add back in the spare chars
    fCharsAvail += spareChars;

    // Reset the buffer index to zero, so we start from the 0th char again
    fCharIndex = 0;

    //
    //  If no chars available, then we have to check for one last thing. If
    //  this is reader for a PE and its not being expanded inside a literal,
    //  then unget a trailing space. We use a boolean to avoid triggering
    //  this more than once.
    //
    if (!fCharsAvail
    &&  (fType == Type_PE)
    &&  (fRefFrom == RefFrom_NonLiteral)
    &&  !fSentTrailingSpace)
    {
        fCharBuf[0] = chSpace;
        fCharsAvail = 1;
        fSentTrailingSpace = true;
    }

    //
    //  If we are on our first block of chars and the encoding is one of the
    //  UTF-16 formats, then check the first char for the BOM and skip over
    //  it manually.
    //
    if (fCharsAvail)
    {
        if ((fCurLine == 1) && (fCurCol == 1))
        {
            if (((fEncoding == XMLRecognizer::UTF_16L)
            ||   (fEncoding == XMLRecognizer::UTF_16B))
            &&  !startInd)
            {
                if ((fCharBuf[startInd] == chUnicodeMarker)
                ||  (fCharBuf[startInd] == chSwappedUnicodeMarker))
                {
                    fCharIndex++;
                }
            }
        }
    }

    //
    //  If we get here with no more chars, then set the fNoMore flag which
    //  lets us optimize and know without checking that no more chars are
    //  available.
    //
    if (!fCharsAvail)
        fNoMore = true;

    return (fCharsAvail != 0);
}



// ---------------------------------------------------------------------------
//  XMLReader: Scanning methods
// ---------------------------------------------------------------------------
bool XMLReader::getName(XMLBuffer& toFill, const bool token)
{
    //  Ok, first lets see if we have chars in the buffer. If not, then lets
    //  reload.
    if (fCharIndex == fCharsAvail)
    {
        if (!refreshCharBuffer())
            return false;
    }

    //  Lets check the first char for being a first name char. If not, then
    //  what's the point in living mannnn? Just give up now. We only do this
    //  if its a name and not a name token that they want.
    if (!token)
    {
        if (fXMLVersion == XMLV1_1 && ((fCharBuf[fCharIndex] >= 0xD800) && (fCharBuf[fCharIndex] <= 0xDB7F))) {
           if ((fCharBuf[fCharIndex+1] < 0xDC00) || (fCharBuf[fCharIndex+1] > 0xDFFF))
               return false;

            // Looks ok, so lets eat it and put it in our buffer
            toFill.append(fCharBuf[fCharIndex++]);
            fCurCol++;
            toFill.append(fCharBuf[fCharIndex++]);
            fCurCol++;
        }
        else {
            if (!isFirstNameChar(fCharBuf[fCharIndex]))
                return false;

            // Looks ok, so lets eat it and put it in our buffer.  Update column also!
            toFill.append(fCharBuf[fCharIndex++]);
            fCurCol++;
        }

    }

    //  And now we loop until we run out of data in this reader or we hit
    //  a non-name char.
    do {

        while (fCharIndex < fCharsAvail)
        {
            //  Check the current char and take it if its a name char. Else
            //  break out.
            if (fXMLVersion == XMLV1_1 && ((fCharBuf[fCharIndex] >= 0xD800) && (fCharBuf[fCharIndex] <= 0xDB7F))) {
               if ((fCharBuf[fCharIndex+1] < 0xDC00) || (fCharBuf[fCharIndex+1] > 0xDFFF))
                   return !toFill.isEmpty();

                toFill.append(fCharBuf[fCharIndex++]);
                fCurCol++;
                toFill.append(fCharBuf[fCharIndex++]);
                fCurCol++;
            }
            else {
                if (!isNameChar(fCharBuf[fCharIndex]))
                {
                    return !toFill.isEmpty();
                }

                toFill.append(fCharBuf[fCharIndex++]);
                fCurCol++;
            }
        }

    // If we don't get no more, then break out.
    } while (refreshCharBuffer());

    return !toFill.isEmpty();
}


bool XMLReader::getSpaces(XMLBuffer& toFill)
{
    //
    //  We just loop until we either hit a non-space or the end of this
    //  entity. We return true if we returned because of a non-space and
    //  false if because of end of entity.
    //
    //  NOTE:   We have to maintain line/col info here and we have to do
    //          whitespace normalization if we are not already internalized.
    //
    while (true)
    {
        // Loop through the current chars in the buffer
        while (fCharIndex < fCharsAvail)
        {
            // Get the current char out of the buffer
            XMLCh curCh = fCharBuf[fCharIndex];

            //
            //  See if its a white space char. If so, then process it. Else
            //  we've hit a non-space and need to return.
            //
            if (isWhitespace(curCh))
            {
                // Eat this char
                fCharIndex++;

                //
                //  Ok, we've got some whitespace here. So we have to store
                //  it. But we have to normalize it and update the line and
                //  column info along the way.
                //
                if (curCh == chCR)
                {
                    fCurCol = 1;
                    fCurLine++;

                    //
                    //  If not already internalized, then convert it to an
                    //  LF and eat any following LF.
                    //
                    if (fSource == Source_External)
                    {
                        if ((fCharIndex < fCharsAvail) || refreshCharBuffer())
                        {
                            if (fCharBuf[fCharIndex] == chLF
                                || ((fCharBuf[fCharIndex] == chNEL) && fNEL))
                                fCharIndex++;
                        }
                        curCh = chLF;
                    }
                }
                 else if (curCh == chLF
                          || ((curCh == chNEL || curCh == chLineSeparator) && fNEL))
                {
                    curCh = chLF;
                    fCurCol = 1;
                    fCurLine++;
                }
                 else
                {
                    fCurCol++;
                }

                // Ok we can add this guy to our buffer
                toFill.append(curCh);
            }
             else
            {
                // Return true to indicate we broke out due to a whitespace
                return true;
            }
        }

        //
        //  We've eaten up the current buffer, so lets try to reload it. If
        //  we don't get anything new, then break out. If we do, then we go
        //  back to the top to keep getting spaces.
        //
        if (!refreshCharBuffer())
            break;
    }
    return false;
}


bool XMLReader::getUpToCharOrWS(XMLBuffer& toFill, const XMLCh toCheck)
{
    while (true)
    {
        // Loop through the current chars in the buffer
        while (fCharIndex < fCharsAvail)
        {
            // Get the current char out of the buffer
            XMLCh curCh = fCharBuf[fCharIndex];

            //
            //  See if its not a white space or our target char, then process
            //  it. Else, we need to return.
            //
            if (!isWhitespace(curCh) && (curCh != toCheck))
            {
                // Eat this char
                fCharIndex++;

                //
                //  Ok, we've got some whitespace here. So we have to store
                //  it. But we have to normalize it and update the line and
                //  column info along the way.
                //
                if (curCh == chCR)
                {
                    fCurCol = 1;
                    fCurLine++;

                    //
                    //  If not already internalized, then convert it to an
                    //  LF and eat any following LF.
                    //
                    if (fSource == Source_External)
                    {
                        if ((fCharIndex < fCharsAvail) || refreshCharBuffer())
                        {
                            if (fCharBuf[fCharIndex] == chLF
                                || ((fCharBuf[fCharIndex] == chNEL) && fNEL))
                                fCharIndex++;
                        }
                        curCh = chLF;
                    }
                }
                 else if (curCh == chLF
                          || ((curCh == chNEL || curCh == chLineSeparator) && fNEL))
                {
                    curCh = chLF;
                    fCurCol = 1;
                    fCurLine++;
                }
                 else
                {
                    fCurCol++;
                }

                // Add it to our buffer
                toFill.append(curCh);
            }
             else
            {
                return true;
            }
        }

        //
        //  We've eaten up the current buffer, so lets try to reload it. If
        //  we don't get anything new, then break out. If we do, then we go
        //  back to the top to keep getting spaces.
        //
        if (!refreshCharBuffer())
            break;
    }

    // We never hit any non-space and ate up the whole reader
    return false;

}

bool XMLReader::skipIfQuote(XMLCh& chGotten)
{
    if (fCharIndex == fCharsAvail)
    {
        if (!refreshCharBuffer())
            return false;
    }

    const XMLCh curCh = fCharBuf[fCharIndex];
    if ((curCh == chDoubleQuote) || (curCh == chSingleQuote))
    {
        chGotten = curCh;
        fCharIndex++;
        fCurCol++;
        return true;
    }
    return false;
}


bool XMLReader::skipSpaces(bool& skippedSomething)
{
    // Remember the current line and column
    XMLSSize_t    orgLine = fCurLine;
    XMLSSize_t    orgCol  = fCurCol;

    //  We enter a loop where we skip over spaces until we hit the end of
    //  this reader or a non-space value. The return indicates whether we
    //  hit the non-space (true) or the end (false).
    while (true)
    {
        // Loop through the current chars in the buffer
        while (fCharIndex < fCharsAvail)
        {
            //  See if its a white space char. If so, then process it. Else
            //  we've hit a non-space and need to return.
            if (isWhitespace(fCharBuf[fCharIndex]))
            {
                // Get the current char out of the buffer and eat it
                XMLCh curCh = fCharBuf[fCharIndex++];

                //  Ok, we've got some whitespace here. So we have to store
                //  it. But we have to normalize it and update the line and
                //  column info along the way.
                if (curCh == chCR)
                {
                    fCurCol = 1;
                    fCurLine++;

                    //  If not already internalized, then convert it to an
                    //  LF and eat any following LF.
                    if (fSource == Source_External)
                    {
                        if ((fCharIndex < fCharsAvail) || refreshCharBuffer())
                        {
                            if (fCharBuf[fCharIndex] == chLF
                                || ((fCharBuf[fCharIndex] == chNEL) && fNEL))
                                fCharIndex++;
                        }
                    }
                }
                else if (curCh == chLF
                         || ((curCh == chNEL || curCh == chLineSeparator) && fNEL))
                {
                    fCurCol = 1;
                    fCurLine++;
                }
                else
                {
                    fCurCol++;
                }
            }
            else
            {
                skippedSomething = (orgLine != fCurLine) || (orgCol != fCurCol);
                return true;
            }
        }

        //  We've eaten up the current buffer, so lets try to reload it. If
        //  we don't get anything new, then break out. If we do, then we go
        //  back to the top to keep getting spaces.
        if (!refreshCharBuffer())
            break;
    }

    // We never hit any non-space and ate up the whole reader
    skippedSomething = (orgLine != fCurLine) || (orgCol != fCurCol);
    return false;
}


bool XMLReader::skippedChar(const XMLCh toSkip)
{
    //
    //  If the buffer is empty, then try to reload it. If we still get
    //  nothing, then return false.
    //
    if (fCharIndex == fCharsAvail)
    {
        if (!refreshCharBuffer())
            return false;
    }

    //
    //  See if the current char is the one we want. If so, then we need
    //  to eat it and return true.
    //
    if (fCharBuf[fCharIndex] == toSkip)
    {
        fCharIndex++;
        fCurCol++;
        return true;
    }
    return false;
}


bool XMLReader::skippedSpace()
{
    //
    //  If the buffer is empty, then try to reload it. If we still get
    //  nothing, then return false.
    //
    if (fCharIndex == fCharsAvail)
    {
        if (!refreshCharBuffer())
            return false;
    }

    //
    //  See if the current char is a whitespace. If so, then we need to eat
    //  it and return true.
    //
    const XMLCh curCh = fCharBuf[fCharIndex];
    if (isWhitespace(curCh))
    {
        // Eat the character
        fCharIndex++;

        if (curCh == chCR)
        {
            fCurLine++;
            fCurCol = 1;

            if (fSource == Source_External)
            {
                if ((fCharIndex < fCharsAvail) || refreshCharBuffer())
                {
                    if (fCharBuf[fCharIndex] == chLF
                        || ((fCharBuf[fCharIndex] == chNEL) && fNEL))
                        fCharIndex++;
                }
            }
        }
         else if (curCh == chLF
                  || ((curCh == chNEL || curCh == chLineSeparator) && fNEL))
        {
            fCurLine++;
            fCurCol = 1;
        }
         else
        {
            fCurCol++;
        }
        return true;
    }
    return false;
}


bool XMLReader::skippedString(const XMLCh* const toSkip)
{
    // Get the length of the string to skip
    const unsigned int srcLen = XMLString::stringLen(toSkip);

    //
    //  See if the current reader has enough chars to test against this
    //  string. If not, then ask it to reload its buffer. If that does not
    //  get us enough, then it cannot match.
    //
    //  NOTE: This works because strings never have to cross a reader! And
    //  a string to skip will never have a new line in it, so we will never
    //  miss adjusting the current line.
    //
    unsigned int charsLeft = charsLeftInBuffer();
    while (charsLeft < srcLen)
    {
         refreshCharBuffer();
         unsigned int t = charsLeftInBuffer();
         if (t == charsLeft)   // if the refreshCharBuf() did not add anything new
             return false;     //   give up and return.
         charsLeft = t;
	}




    //
    //  Ok, now we now that the current reader has enough chars in its
    //  buffer and that its index is back at zero. So we can do a quick and
    //  dirty comparison straight to its buffer with no requirement to unget
    //  if it fails.
    //
    if (XMLString::compareNString(&fCharBuf[fCharIndex], toSkip, srcLen))
        return false;

    // Add the source length to the current column to get it back right
    fCurCol += srcLen;

    //
    //  And get the character buffer index back right by just adding the
    //  source len to it.
    //
    fCharIndex += srcLen;

    return true;
}

//
// This is just to peek if the next coming buffer
// matches the string toPeek.
// Similar to skippedString, but just the fCharIndex and fCurCol are not updated
//
bool XMLReader::peekString(const XMLCh* const toPeek)
{
    // Get the length of the string to skip
    const unsigned int srcLen = XMLString::stringLen(toPeek);

    //
    //  See if the current reader has enough chars to test against this
    //  string. If not, then ask it to reload its buffer. If that does not
    //  get us enough, then it cannot match.
    //
    //  NOTE: This works because strings never have to cross a reader! And
    //  a string to skip will never have a new line in it, so we will never
    //  miss adjusting the current line.
    //
    unsigned int charsLeft = charsLeftInBuffer();
    while (charsLeft < srcLen)
    {
         refreshCharBuffer();
         unsigned int t = charsLeftInBuffer();
         if (t == charsLeft)   // if the refreshCharBuf() did not add anything new
             return false;     //   give up and return.
         charsLeft = t;
	}




    //
    //  Ok, now we now that the current reader has enough chars in its
    //  buffer and that its index is back at zero. So we can do a quick and
    //  dirty comparison straight to its buffer with no requirement to unget
    //  if it fails.
    //
    if (XMLString::compareNString(&fCharBuf[fCharIndex], toPeek, srcLen))
        return false;

    return true;
}


// ---------------------------------------------------------------------------
//  XMLReader: Setter methods (most are inlined)
// ---------------------------------------------------------------------------
bool XMLReader::setEncoding(const XMLCh* const newEncoding)
{
    //
    //  If the encoding was forced, then we ignore the new value and just
    //  return with success. If it was forced, then we are to use that
    //  encoding without question. Note that, if we are forced, we created
    //  a transcoder up front so there is no need to do one here in that
    //  case.
    //
    if (fForcedEncoding)
        return true;

    //
    // upperCase the newEncoding first for better performance
    //
    XMLCh* inputEncoding = XMLString::replicate(newEncoding, fMemoryManager);
    XMLString::upperCase(inputEncoding);

    //
    //  Try to map the string to one of our standard encodings. If its not
    //  one of them, then it has to be one of the non-intrinsic encodings,
    //  in which case we have to delete our intrinsic encoder and create a
    //  new one.
    //
    XMLRecognizer::Encodings newBaseEncoding = XMLRecognizer::encodingForName
    (
        inputEncoding
    );

    //
    //  If it does not come back as one of the auto-sensed encodings, then we
    //  have to possibly replace it and at least check a few things.
    //
    if (newBaseEncoding == XMLRecognizer::OtherEncoding)
    {
        //
        //  Check for non-endian specific UTF-16 or UCS-4. If so, and if we
        //  are already in one of the endian versions of those encodings,
        //  then just keep it and go on. Otherwise, its not valid.
        //
        if (!XMLString::compareString(inputEncoding, XMLUni::fgUTF16EncodingString)
        ||  !XMLString::compareString(inputEncoding, XMLUni::fgUTF16EncodingString2)
        ||  !XMLString::compareString(inputEncoding, XMLUni::fgUTF16EncodingString3)
        ||  !XMLString::compareString(inputEncoding, XMLUni::fgUTF16EncodingString4)
        ||  !XMLString::compareString(inputEncoding, XMLUni::fgUTF16EncodingString5))
        {
            fMemoryManager->deallocate(inputEncoding);

            if ((fEncoding != XMLRecognizer::UTF_16L)
            &&  (fEncoding != XMLRecognizer::UTF_16B))
            {
                return false;
            }

            // Override with the original endian specific encoding
            newBaseEncoding = fEncoding;

            if (fEncoding == XMLRecognizer::UTF_16L) {
                fMemoryManager->deallocate(fEncodingStr);
                fEncodingStr = XMLString::replicate(XMLUni::fgUTF16LEncodingString, fMemoryManager);
            }
            else {
                fMemoryManager->deallocate(fEncodingStr);
                fEncodingStr = XMLString::replicate(XMLUni::fgUTF16BEncodingString, fMemoryManager);
            }
        }
        else if (!XMLString::compareString(inputEncoding, XMLUni::fgUCS4EncodingString)
             ||  !XMLString::compareString(inputEncoding, XMLUni::fgUCS4EncodingString2)
             ||  !XMLString::compareString(inputEncoding, XMLUni::fgUCS4EncodingString3))
        {
            fMemoryManager->deallocate(inputEncoding);

            if ((fEncoding != XMLRecognizer::UCS_4L)
            &&  (fEncoding != XMLRecognizer::UCS_4B))
            {
                return false;
            }

            // Override with the original endian specific encoding
            newBaseEncoding = fEncoding;

            if (fEncoding == XMLRecognizer::UCS_4L) {

                fMemoryManager->deallocate(fEncodingStr);
                fEncodingStr = XMLString::replicate(XMLUni::fgUCS4LEncodingString, fMemoryManager);
            }
            else {

                fMemoryManager->deallocate(fEncodingStr);
                fEncodingStr = XMLString::replicate(XMLUni::fgUCS4BEncodingString, fMemoryManager);
            }
        }
         else
        {
            //
            // None of those special cases, so just replicate the new name
            // and use it directly to create the transcoder
            //
            fMemoryManager->deallocate(fEncodingStr);
            fEncodingStr = inputEncoding;

            XMLTransService::Codes failReason;
            fTranscoder = XMLPlatformUtils::fgTransService->makeNewTranscoderFor
            (
                fEncodingStr
                , failReason
                , kCharBufSize
                , fMemoryManager
            );
        }
    }
     else
    {
        // Store the new encoding string since it is just an intrinsic
        fMemoryManager->deallocate(fEncodingStr);
        fEncodingStr = inputEncoding;
    }

    if (!fTranscoder) {
        //
        //  Now we can create a transcoder using the recognized fEncoding.  We
        //  might get back a transcoder for an intrinsically supported encoding,
        //  or we might get one from the underlying transcoding service.
        //
        XMLTransService::Codes failReason;
        fTranscoder = XMLPlatformUtils::fgTransService->makeNewTranscoderFor
        (
            newBaseEncoding
            , failReason
            , kCharBufSize
            , fMemoryManager
        );

        if (!fTranscoder)
            ThrowXMLwithMemMgr1(TranscodingException, XMLExcepts::Trans_CantCreateCvtrFor, fEncodingStr, fMemoryManager);
    }

    // Update the base encoding member with the new base encoding found
    fEncoding = newBaseEncoding;

    // Looks ok to us
    return true;
}


// ---------------------------------------------------------------------------
//  XMLReader: Private helper methods
// ---------------------------------------------------------------------------

//
//  This is called when the encoding flag is set and just sets the fSwapped
//  flag appropriately.
//
void XMLReader::checkForSwapped()
{
    // Assume not swapped
    fSwapped = false;

    #if defined(ENDIANMODE_LITTLE)

        if ((fEncoding == XMLRecognizer::UTF_16B)
        ||  (fEncoding == XMLRecognizer::UCS_4B))
        {
            fSwapped = true;
        }

    #elif defined(ENDIANMODE_BIG)

        if ((fEncoding == XMLRecognizer::UTF_16L)
        ||  (fEncoding == XMLRecognizer::UCS_4L))
        {
            fSwapped = true;
        }

    #endif
}


//
//  This is called from the constructor when the encoding is not forced.
//  We assume that the encoding has been auto-sensed at this point and that
//  fSwapped is set correctly.
//
//  In the case of UCS-4 and EBCDIC, we don't have to check for a decl.
//  The fact that we got here, means that there is one, because that's the
//  only way we can autosense those.
//
void XMLReader::doInitDecode()
{
    switch(fEncoding)
    {
        case XMLRecognizer::UCS_4B :
        case XMLRecognizer::UCS_4L :
        {
            // Remove bom if any
            if (((fRawByteBuf[0] == 0x00) && (fRawByteBuf[1] == 0x00) && (fRawByteBuf[2] == 0xFE) && (fRawByteBuf[3] == 0xFF)) ||
                ((fRawByteBuf[0] == 0xFF) && (fRawByteBuf[1] == 0xFE) && (fRawByteBuf[2] == 0x00) && (fRawByteBuf[3] == 0x00))  )
            {
                for (unsigned int i = 0; i < fRawBytesAvail; i++)
                    fRawByteBuf[i] = fRawByteBuf[i+4];

                fRawBytesAvail -=4;
            }

            // Look at the raw buffer as UCS4 chars
            const UCS4Ch* asUCS = (const UCS4Ch*)fRawByteBuf;

            while (fRawBufIndex < fRawBytesAvail)
            {
                // Get out the current 4 byte value and inc our raw buf index
                UCS4Ch curVal = *asUCS++;
                fRawBufIndex += sizeof(UCS4Ch);

                // Swap if that is required for this machine
                if (fSwapped)
                    curVal = BitOps::swapBytes(curVal);

                // Make sure its at least semi legal. If not, undo and throw
                if (curVal > 0xFFFF)
                {
                    fCharsAvail = 0;
                    fRawBufIndex = 0;
                    fMemoryManager->deallocate(fPublicId);
                    fMemoryManager->deallocate(fEncodingStr);
                    ArrayJanitor<XMLCh> janValue(fSystemId, fMemoryManager);
                    ThrowXMLwithMemMgr1
                    (
                        TranscodingException
                        , XMLExcepts::Reader_CouldNotDecodeFirstLine
                        , fSystemId
                        , fMemoryManager
                    );
                }

                // Convert the value to an XML char and store it
                fCharSizeBuf[fCharsAvail] = 4;
                fCharBuf[fCharsAvail++] = XMLCh(curVal);

                // Break out on the > character
                if (curVal == chCloseAngle)
                    break;
            }
            break;
        }

        case XMLRecognizer::UTF_8 :
        {
            // If there's a utf-8 BOM  (0xEF 0xBB 0xBF), skip past it.
            //   Don't move to char buf - no one wants to see it.
            //   Note: this causes any encoding= declaration to override
            //         the BOM's attempt to say that the encoding is utf-8.

            // Look at the raw buffer as short chars
            const char* asChars = (const char*)fRawByteBuf;

            if (fRawBytesAvail > XMLRecognizer::fgUTF8BOMLen &&
                XMLString::compareNString(  asChars
                                            , XMLRecognizer::fgUTF8BOM
                                            , XMLRecognizer::fgUTF8BOMLen) == 0)
            {
                fRawBufIndex += XMLRecognizer::fgUTF8BOMLen;
                asChars      += XMLRecognizer::fgUTF8BOMLen;
            }

            //
            //  First check that there are enough bytes to even see the
            //  decl indentifier. If not, get out now with no action since
            //  there is no decl.
            //
            if (fRawBytesAvail < XMLRecognizer::fgASCIIPreLen)
                break;

            // Check for the opening sequence. If not, then no decl
            if (XMLString::compareNString(  asChars
                                            , XMLRecognizer::fgASCIIPre
                                            , XMLRecognizer::fgASCIIPreLen))
            {
                break;
            }

            while (fRawBufIndex < fRawBytesAvail)
            {
                const char curCh = *asChars++;
                fRawBufIndex++;

                // Looks ok, so store it
                fCharSizeBuf[fCharsAvail] = 1;
                fCharBuf[fCharsAvail++] = XMLCh(curCh);

                // Break out on a > character
                if (curCh == chCloseAngle)
                    break;

                //
                //  A char greater than 0x7F is not allowed in this case. If
                //  so, undo and throw.
                //
                if (curCh & 0x80)
                {
                    fCharsAvail = 0;
                    fRawBufIndex = 0;
                    fMemoryManager->deallocate(fPublicId);
                    fMemoryManager->deallocate(fEncodingStr);
                    ArrayJanitor<XMLCh> janValue(fSystemId, fMemoryManager);
                    ThrowXMLwithMemMgr1
                    (
                        TranscodingException
                        , XMLExcepts::Reader_CouldNotDecodeFirstLine
                        , fSystemId
                        , fMemoryManager
                    );
                }
            }
            break;
        }

        case XMLRecognizer::UTF_16B :
        case XMLRecognizer::UTF_16L :
        {
            //
            //  If there is a decl here, we just truncate back the characters
            //  as we go. No surrogate creation would be allowed here in legal
            //  XML, so we consider it a transoding error if we find one.
            //
            if (fRawBytesAvail < 2)
                break;

            const UTF16Ch* asUTF16 = (const UTF16Ch*)&fRawByteBuf[fRawBufIndex];
            if ((*asUTF16 == chUnicodeMarker) || (*asUTF16 == chSwappedUnicodeMarker))
            {
                fRawBufIndex += sizeof(UTF16Ch);
                asUTF16++;
            }

            //  First check that there are enough raw bytes for there to even
            //  be a decl indentifier. If not, then nothing to do.
            //
            if (fRawBytesAvail - fRawBufIndex < XMLRecognizer::fgUTF16PreLen)
            {
                fRawBufIndex = 0;
                break;
            }

            //
            //  See we get a match on the prefix. If not, then reset and
            //  break out.
            //
            if (fEncoding == XMLRecognizer::UTF_16B)
            {
                if (memcmp(asUTF16, XMLRecognizer::fgUTF16BPre, XMLRecognizer::fgUTF16PreLen))
                {
                    fRawBufIndex = 0;
                    break;
                }
            }
             else
            {
                if (memcmp(asUTF16, XMLRecognizer::fgUTF16LPre, XMLRecognizer::fgUTF16PreLen))
                {
                    fRawBufIndex = 0;
                    break;
                }
            }

            while (fRawBufIndex < fRawBytesAvail)
            {
                // Get out the current 2 byte value
                UTF16Ch curVal = *asUTF16++;
                fRawBufIndex += sizeof(UTF16Ch);

                // Swap if that is required for this machine
                if (fSwapped)
                    curVal = BitOps::swapBytes(curVal);

                //
                //  Store it and bump the target index, implicitly converting
                //  if UTF16Ch and XMLCh are not the same size.
                //
                fCharSizeBuf[fCharsAvail] = 2;
                fCharBuf[fCharsAvail++] = curVal;

                // Break out on a > char
                if (curVal == chCloseAngle)
                    break;
            }
            break;
        }

        case XMLRecognizer::EBCDIC :
        {
            //
            //  We use special support in the intrinsic EBCDIC-US transcoder
            //  to go through one char at a time.
            //
            const XMLByte* srcPtr = fRawByteBuf;
            while (1)
            {
                // Transcode one char from the source
                const XMLCh chCur = XMLEBCDICTranscoder::xlatThisOne(*srcPtr++);
                fRawBufIndex++;

                //
                //  And put it into the character buffer. This stuff has to
                //  look like it was normally transcoded.
                //
                fCharSizeBuf[fCharsAvail] = 1;
                fCharBuf[fCharsAvail++] = chCur;

                // If its a > char, then break out
                if (chCur == chCloseAngle)
                    break;

                // Watch for using up all input and get out
                if (fRawBufIndex == fRawBytesAvail)
                    break;
            }
            break;
        }

        default :
            // It should never be anything else here
            fMemoryManager->deallocate(fPublicId);
            fMemoryManager->deallocate(fEncodingStr);                    
            fMemoryManager->deallocate(fSystemId);
            ThrowXMLwithMemMgr(TranscodingException, XMLExcepts::Reader_BadAutoEncoding, fMemoryManager);
            break;
    }

    //
    //  Ok, by the time we get here, if its a legal XML file we have eaten
    //  the XML/TextDecl. So, if we are a PE and are being referenced from
    //  outside a literal, then we need to throw in an arbitrary space that
    //  is required by XML.
    //
    if ((fType == Type_PE) && (fRefFrom == RefFrom_NonLiteral))
        fCharBuf[fCharsAvail++] = chSpace;
}


//
//  This method is called internally when we run out of bytes in the raw
//  buffer. We just read as many bytes as we can into the raw buffer again
//  and store the number of bytes we got.
//
void XMLReader::refreshRawBuffer()
{
    //
    //  If there are any bytes left, move them down to the start. There
    //  should only ever be (max bytes per char - 1) at the most.
    //
    const unsigned int bytesLeft = fRawBytesAvail - fRawBufIndex;

    // Move the existing ones down
    for (unsigned int index = 0; index < bytesLeft; index++)
        fRawByteBuf[index] = fRawByteBuf[fRawBufIndex + index];

    //
    //  And then read into the buffer past the existing bytes. Add back in
    //  that many to the bytes read, and subtract that many from the bytes
    //  requested.
    //
    fRawBytesAvail = fStream->readBytes
    (
        &fRawByteBuf[bytesLeft], kRawBufSize - bytesLeft
    ) + bytesLeft;

    //
    //  We need to reset the buffer index back to the start in all cases,
    //  since any trailing data was copied down to the start.
    //
    fRawBufIndex = 0;
}


//
//  This method is called internally when we run out of characters in the
//  trancoded character buffer. We transcode up to another maxChars chars
//  from the
//
unsigned int
XMLReader::xcodeMoreChars(          XMLCh* const            bufToFill
                            ,       unsigned char* const    charSizes
                            , const unsigned int            maxChars)
{
    // If we are plain tuckered out, then return zero now
    if (!fRawBytesAvail)
        return 0;

    //
    //  If our raw buffer is low, then lets load up another batch of
    //  raw bytes now.  We can't check for exactly zero bytes left because
    //  transcoding of multi-byte encodings may have left a few bytes
    //  representing a partial character in the buffer that can't be
    //  used until the next buffer (and the rest of the character)
    //  is read.
    //
    unsigned int bytesLeft = fRawBytesAvail - fRawBufIndex;
    if (bytesLeft < 100)
    {
        refreshRawBuffer();

        // If we didn't get anything more just return a zero now
        if (!fRawBytesAvail)
            return 0;
    }

    // Ask the transcoder to internalize another batch of chars
    unsigned int bytesEaten;
    const unsigned int charsDone = fTranscoder->transcodeFrom
    (
        &fRawByteBuf[fRawBufIndex]
        , fRawBytesAvail - fRawBufIndex
        , bufToFill
        , maxChars
        , bytesEaten
        , charSizes
    );

    // Update the raw buffer index
    fRawBufIndex += bytesEaten;

    return charsDone;
}

XERCES_CPP_NAMESPACE_END