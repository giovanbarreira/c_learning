#include <stdio.h>
#include <curl/curl.h>

// sudo apt update
// sudo apt install libcurl4-openssl-dev
// gcc azure.c -o out -lcurl

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    fwrite(ptr, size, nmemb, stdout);
    return size * nmemb;
}

int main(void) {
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.15.20:7235/api/Function1");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return 0;
}