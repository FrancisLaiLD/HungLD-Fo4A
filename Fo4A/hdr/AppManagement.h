#ifndef __APP__MANAGEMENT__H__
#define __APP__MANAGEMENT__H__

#include <iostream>

#include <CkFileAccess.h>
#include <CkRest.h>
#include <CkAuthGoogle.h>
#include <CkJsonObject.h>

class AppManagement
{
public:
    AppManagement();
    ~AppManagement();
    void ChilkatSample(void)
    {
    //  Push a new record to a Firebase JSON database using the POST HTTP method.

    //  This example requires the Chilkat API to have been previously unlocked.
    //  See Global Unlock Sample for sample code.

    //  This example assumes a JWT authentication token, if required, has been previously obtained.
    //  See Get Firebase Access Token from JSON Service Account Private Key for sample code.

    //  Load the previously obtained Firebase access token into a string.
    CkFileAccess fac;
    const char *accessToken = fac.readEntireTextFile("qa_data/tokens/firebaseToken.txt","utf-8");
    if (fac.get_LastMethodSuccess() != true) {
        std::cout << fac.lastErrorText() << "\r\n";
        return;
    }

    CkRest rest;

    //  Make the initial connection (without sending a request yet).
    //  Once connected, any number of requests may be sent.  It is not necessary to explicitly
    //  call Connect before each request.
    bool success = rest.Connect("chilkat.firebaseio.com",443,true,true);
    if (success != true) {
        std::cout << rest.lastErrorText() << "\r\n";
        return;
    }

    CkAuthGoogle authGoogle;
    authGoogle.put_AccessToken(accessToken);
    rest.SetAuthGoogle(authGoogle);

    //  Chilkat's sample data (pig-rescue data) is publicly readable at: https://chilkat.firebaseio.com/.json
    //  This data is publicly readable, but not writable.  You'll need to
    //  run against your own database..

    //  We're going to add a new pig with just the name.
    CkJsonObject pigRecord;
    pigRecord.AppendString("name","William");

    //  The string content of the last arg passed is  {"name":"William"}
    const char *jsonResponse = rest.fullRequestString("POST","/pig-rescue/animal.json",pigRecord.emit());
    if (rest.get_LastMethodSuccess() != true) {
        //  Something happened in the communications (either no request was sent, or no response was received.
        //  (The Chilkat REST API also has lower-level methods where an app can send the request in one call,
        //  and then receive the response in another call.)
        std::cout << rest.lastErrorText() << "\r\n";
        return;
    }

    //  Check the response status code.   A 200 response status indicates success.
    if (rest.get_ResponseStatusCode() != 200) {
        std::cout << rest.responseStatusText() << "\r\n";
        std::cout << jsonResponse << "\r\n";
        std::cout << "Failed." << "\r\n";
        return;
    }

    //  Get the push ID generated by Firebase
    CkJsonObject resp;
    resp.Load(jsonResponse);
    const char *pushId = resp.stringOf("name");
    std::cout << "Added record with push ID " << pushId << "\r\n";
    std::cout << "Success." << "\r\n";
    }

};

#endif // __APP__MANAGEMENT__H__
