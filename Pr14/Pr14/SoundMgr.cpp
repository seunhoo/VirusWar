#include "stdafx.h"
#include "SoundMgr.h"

void SoundMgr::Play(const WCHAR* pFileName, bool loop)
{
	WCHAR szFile[256] = L"../Sound/";
	lstrcat(szFile, pFileName);

	if (!loop)
	{
		PlaySound(szFile, NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP);
	}
	else
	{
		PlaySound(szFile, NULL, SND_ASYNC | SND_FILENAME | SND_NOSTOP | SND_NOSTOP);
	}
}

void SoundMgr::Stop()
{
	PlaySound(nullptr, NULL, SND_ASYNC);
}
