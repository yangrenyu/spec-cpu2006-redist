/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 1999-2001 The Apache Software Foundation.  All rights
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
 * $Id: XMLDOMDocumentType.cpp,v 1.1.1.1 2002/02/01 22:21:41 peiyongz Exp $
 */

#include "stdafx.h"
#include "xml4com.h"
#include "XMLDOMDocumentType.h"
#include "XMLDOMNamedNodeMap.h"

// IXMLDOMDocumentType methods
STDMETHODIMP CXMLDOMDocumentType::get_name(BSTR  *pVal)
{
	ATLTRACE(_T("CXMLDOMDocumentType::get_name\n"));

	if (NULL == pVal)
		return E_POINTER;

	*pVal = NULL;

	try
	{
		DOMString val = documentType.getName();
		*pVal = SysAllocStringLen(val.rawBuffer(),val.length());
	}
	catch(DOM_DOMException& ex)
	{
		return MakeHRESULT(ex);
	}
	catch(...)
	{
		return E_FAIL;
	}
	

	return S_OK;
}

STDMETHODIMP CXMLDOMDocumentType::get_entities(IXMLDOMNamedNodeMap  **pVal)
{
	ATLTRACE(_T("CXMLDOMDocumentType::get_entities\n"));

	if (NULL == pVal)
		return E_POINTER;

	*pVal = NULL;

	CXMLDOMNamedNodeMapObj *pObj = NULL;
	HRESULT hr = CXMLDOMNamedNodeMapObj::CreateInstance(&pObj);
	if (S_OK != hr)
		return hr;
	
	pObj->AddRef();
	pObj->SetOwnerDoc(m_pIXMLDOMDocument);

	try
	{
		pObj->m_container = documentType.getEntities();
	}
	catch(DOM_DOMException& ex)
	{
		pObj->Release();
		return MakeHRESULT(ex);
	}
	catch(...)
	{
		pObj->Release();
		return E_FAIL;
	}
	
	hr = pObj->QueryInterface(IID_IXMLDOMNamedNodeMap, reinterpret_cast<LPVOID*> (pVal));
	if (S_OK != hr)
		*pVal = NULL;

	pObj->Release();
	return hr;
}

STDMETHODIMP CXMLDOMDocumentType::get_notations(IXMLDOMNamedNodeMap  **pVal)
{
	ATLTRACE(_T("CXMLDOMDocumentType::get_notations\n"));

	if (NULL == pVal)
		return E_POINTER;

	*pVal = NULL;

	CXMLDOMNamedNodeMapObj *pObj = NULL;
	HRESULT hr = CXMLDOMNamedNodeMapObj::CreateInstance(&pObj);
	if (S_OK != hr)
		return hr;
	
	pObj->AddRef();
	pObj->SetOwnerDoc(m_pIXMLDOMDocument);

	try
	{
		pObj->m_container = documentType.getNotations();
	}
	catch(DOM_DOMException& ex)
	{
		pObj->Release();
		return MakeHRESULT(ex);
	}
	catch(...)
	{
		pObj->Release();
		return E_FAIL;
	}
	
	hr = pObj->QueryInterface(IID_IXMLDOMNamedNodeMap, reinterpret_cast<LPVOID*> (pVal));
	if (S_OK != hr)
		*pVal = NULL;

	pObj->Release();
	return hr;

}