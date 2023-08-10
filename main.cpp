#include "pch.h"
int main()
{
	LPCTSTR pszReportJson = TEXT("C:/Users/liku9/OneDrive/바탕 화면/GIT/report.json"); // 본인 경로에 맞게 수정1
	LPCTSTR pszReportXml = TEXT("C:/Users/liku9/OneDrive/바탕 화면/GIT/report.xml"); // 본인 경로에 맞게 수정2
	LPCTSTR pszTargetXml = TEXT("C:/Users/liku9/OneDrive/바탕 화면/GIT/target.xml"); // 본인 경로에 맞게 수정3
	try
	{
		ST_REPORT report;
		

		if (!UTF8::ReadJsonFromFile(&report, pszReportJson))
			throw exception_format(TEXT("Reading %s failure"), pszReportJson);
		if (!UTF8::WriteXmlToFile(&report, pszReportXml))
			throw exception_format(TEXT("Writing %s failure"), pszReportXml);
		std::tstring strMyXml;
		if (EC_SUCCESS != ReadFileContents(pszReportXml, strMyXml))
			throw exception_format(TEXT("Reading MyXml %s failure"), pszReportXml);
		std::tstring strTargetXml;
		if (EC_SUCCESS != ReadFileContents(pszTargetXml, strTargetXml))
			throw exception_format(TEXT("Reading TargetXml %s failure"), pszTargetXml);
		if (strMyXml != strTargetXml)
			throw exception_format(TEXT("Not exactly matched!"));
		printf("You are succeeded!\n");
	}
	catch (const std::exception& e)
	{
		printf("%s\n", e.what());
		return -1;
	}
	return 0;
}