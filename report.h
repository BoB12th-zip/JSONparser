#pragma once

struct ST_SUMMARY : public core::IFormatterObject
{
    std::tstring strResult;
    std::tstring strDetectName;
    std::tstring strEngineName;
    std::tstring strEngineVersion;
    int Severity;
    std::tstring strSampleName;
    std::tstring strSampleExt;
    int CurLoopCount;
    int MaxLoopCount;
    double TotalElapsedTime;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("Result"), strResult)
            + core::sPair(TEXT("DetectName"), strDetectName)
            + core::sPair(TEXT("EngineName"), strEngineName)
            + core::sPair(TEXT("EngineVersion"), strEngineVersion)
            + core::sPair(TEXT("Severity"), Severity)
            + core::sPair(TEXT("SampleName"), strSampleName)
            + core::sPair(TEXT("SampleExt"), strSampleExt)
            + core::sPair(TEXT("CurLoopCount"), CurLoopCount)
            + core::sPair(TEXT("MaxLoopCount"), MaxLoopCount)
            + core::sPair(TEXT("TotalElapsedTime"), TotalElapsedTime)
            ;
    }
};

struct ST_VBS : public core::IFormatterObject
{
    std::tstring strTargetID;
    std::tstring strParentID;
    std::tstring strAbsolutePath;
    std::tstring strFileName;
    int FileSize;
    std::tstring strFileEXT;
    std::tstring strMD5;
    std::tstring strSHA1;
    std::tstring strSHA256;
    std::tstring strHAS160;
    std::tstring strFileHeaderDump;
    int IsExtractedFile;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("TargetID"), strTargetID)
            + core::sPair(TEXT("ParentID"), strParentID)
            + core::sPair(TEXT("AbsolutePath"), strAbsolutePath)
            + core::sPair(TEXT("FileName"), strFileName)
            + core::sPair(TEXT("FileSize"), FileSize)
            + core::sPair(TEXT("FileEXT"), strFileEXT)
            + core::sPair(TEXT("MD5"), strMD5)
            + core::sPair(TEXT("SHA1"), strSHA1)
            + core::sPair(TEXT("SHA256"), strSHA256)
            + core::sPair(TEXT("HAS160"), strHAS160)
            + core::sPair(TEXT("FileHeaderDump"), strFileHeaderDump)
            + core::sPair(TEXT("IsExtractedFile"), IsExtractedFile)
            ;
    }
};

struct ST_TARGETFILE : public core::IFormatterObject
{
    ST_VBS VBS;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("1777336a2b446fbca3172d309884ee65e4e6c0655b3ce1a38301a9c6d61f7195.vbs"), VBS)
            ;
    }
};

struct ST_TARGETS : public core::IFormatterObject
{
    ST_TARGETFILE Targetfile;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("TargetFile"), Targetfile)
            ;
    }
};

struct ST_EVENT : public core::IFormatterObject
{
    std::tstring strEngineName;
    std::tstring strEngineVersion;
    std::tstring strTargetID;
    std::tstring strPlatformID;
    std::tstring strName;
    std::tstring strAnalysisCode;
    int strSeverity;
    std::tstring strDesc;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("EngineName"), strEngineName)
            + core::sPair(TEXT("EngineVersion"), strEngineVersion)
            + core::sPair(TEXT("TargetID"), strTargetID)
            + core::sPair(TEXT("PlatformID"), strPlatformID)
            + core::sPair(TEXT("Name"), strName)
            + core::sPair(TEXT("AnalysisCode"), strAnalysisCode)
            + core::sPair(TEXT("Severity"), strSeverity)
            + core::sPair(TEXT("Desc"), strDesc)
            ;
    }
};

struct ST_DETECTION : public core::IFormatterObject
{
    std::list<ST_EVENT> lt;

    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("Event"), lt)
            ;
    }
};


struct ST_REPORT : public core::IFormatterObject
{
    ST_SUMMARY Summary;
    ST_TARGETS Targets;
    ST_DETECTION Detection;
    void OnSync(core::IFormatter& formatter)
    {
        formatter
            + core::sPair(TEXT("Summary"), Summary)
            + core::sPair(TEXT("Targets"), Targets)
            + core::sPair(TEXT("Detection"), Detection)
            ;
    }
};