#pragma once

#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#define _WIN32_WINNT 0x0502
#include <SDKDDKVer.h>
#include <afxinet.h>
#include <string>


#define  IE_AGENT  _T("Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 2.0.50727)")

// �����ɹ�
#define SUCCESS        0
// ����ʧ��
#define FAILURE        1
// ������ʱ
#define OUTTIME        2

class CHttpClient
{
public:
	CHttpClient(LPCTSTR strAgent = IE_AGENT);
	virtual ~CHttpClient(void);

	int HttpGet(LPCTSTR strUrl, LPCTSTR strPostData, std::wstring &strResponse);
	int HttpPost(LPCTSTR strUrl, LPCTSTR strPostData, std::wstring &strResponse);

private:
	void Clear();

	int ExecuteRequest(LPCTSTR strMethod, LPCTSTR strUrl, LPCTSTR strPostData, std::wstring & strResponse);

private:
	CInternetSession *m_pSession;
	CHttpConnection *m_pConnection;
	CHttpFile *m_pFile;
};

#endif // HTTPCLIENT_H