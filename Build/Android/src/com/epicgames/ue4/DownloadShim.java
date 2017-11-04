package com.epicgames.ue4;

import com.JJ.Amody.OBBDownloaderService;
import com.JJ.Amody.DownloaderActivity;


public class DownloadShim
{
	public static OBBDownloaderService DownloaderService;
	public static DownloaderActivity DownloadActivity;
	public static Class<DownloaderActivity> GetDownloaderType() { return DownloaderActivity.class; }
}

