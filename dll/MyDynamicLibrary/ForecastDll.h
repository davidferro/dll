#pragma once
// FORECAST.H
#using <mscorlib.dll>
#using <System.dll>

using namespace System;
using namespace System::Net;


	class Forecast
	{
	public:
		__declspec(dllexport) Forecast();

		__declspec(dllexport) Forecast(int zip);

		__declspec(dllexport) ~Forecast();

		__declspec(dllexport) void setZipCode(int zip);

		__declspec(dllexport) int getZipCode();

		__declspec(dllexport) void getInfo();

	private:

		int zipcode;
	
	};
