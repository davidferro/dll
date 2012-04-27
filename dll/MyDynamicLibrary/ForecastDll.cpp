#include "ForecastDll.h"
#using <mscorlib.dll>
#using <System.dll>
#using <System.Xml.dll>

using namespace System;
using namespace System::Net;
using namespace System::Xml;

Forecast::Forecast()
{

	zipcode = 0;
	//System::String^ str = "Hi, imma Str";
	//printf("blah =%s\n",blah);
	//printf("String^ =%s\n", str);
	//System::String^ temp = gcnew String(blah.c_str());
	//printf("String^+blah =%s\n",temp);

}

Forecast::Forecast(int zip)
{
	zipcode = zip;
}

Forecast::~Forecast()
{

}

void Forecast::setZipCode(int zip)
{
	zipcode = zip;
}

int Forecast::getZipCode()
{
	return zipcode;
}

void Forecast::getInfo()
{
	//System::Net::HttpWebRequest^ myRequest = dynamic_cast<HttpWebRequest^>(WebRequest::Create( "http://graphical.weather.gov/xml/sample_products/browser_interface/ndfdXMLclient.php?whichClient=NDFDgen&lat=38.99&lon=-77.01&listLatLon=&lat1=&lon1=&lat2=&lon2=&resolutionSub=&listLat1=&listLon1=&listLat2=&listLon2=&resolutionList=&endPoint1Lat=&endPoint1Lon=&endPoint2Lat=&endPoint2Lon=&listEndPoint1Lat=&listEndPoint1Lon=&listEndPoint2Lat=&listEndPoint2Lon=&zipCodeList=&listZipCodeList=&centerPointLat=&centerPointLon=&distanceLat=&distanceLon=&resolutionSquare=&listCenterPointLat=&listCenterPointLon=&listDistanceLat=&listDistanceLon=&listResolutionSquare=&citiesLevel=&listCitiesLevel=&sector=&gmlListLatLon=&featureType=&requestedTime=&startTime=&endTime=&compType=&propertyName=&product=time-series&begin=2004-01-01T00%3A00%3A00&end=2016-01-20T00%3A00%3A00&Unit=e&maxt=maxt&Submit=Submit" ));
	System::Net::HttpWebRequest^ myRequest = dynamic_cast<HttpWebRequest^>(WebRequest::Create( "http://api.hostip.info/get_html.php?&position=true" ));
	System::Net::WebResponse^ myResponse = myRequest->GetResponse();

	// Obtain a 'Stream' object associated with the response object.
	System::IO::Stream^ ReceiveStream = myResponse->GetResponseStream();

	System::Text::Encoding^ encode = System::Text::Encoding::GetEncoding( "utf-8" );

	// Pipe the stream to a higher level stream reader with the required encoding format.
	System::IO::StreamReader^ readStream = gcnew System::IO::StreamReader( ReceiveStream,encode );
	Console::WriteLine( "\nResponse stream received" );
	array<Char>^ read = gcnew array<Char>(256);

	// Read 256 charcters at a time.
	int count = readStream->Read( read, 0, 256 );
	Console::WriteLine( "HTML...\r\n" );
	while ( count > 0 )
	{
	   // Dump the 256 characters on a string and display the string onto the console.
	   String^ str = gcnew String( read,0,count );
	   Console::Write( str );
	   count = readStream->Read( read, 0, 256 );
	}

	Console::WriteLine( "" );
	// Release the resources of stream object.
	readStream->Close();

	// Release the resources of response object.
	myResponse->Close();

	Console::Read();
	

}

