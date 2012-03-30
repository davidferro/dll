// MyExecRefsDll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ForecastDll.h"
#using <mscorlib.dll>


int _tmain(int argc, _TCHAR* argv[])
{
	Forecast* mpForecast = new Forecast();

	//printf("zip =%d",mpForecast->getZipCode());
	mpForecast->getInfo();

	delete mpForecast;
	return 0;
}

