#include <iostream>
#include <string.h>
#include <curl/curl.h>


int main() {
  CURL *curl = curl_easy_init();
  if(curl) {
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_NOBODY, true);
    curl_easy_setopt(curl, CURLOPT_URL, "https://vk.com");
    res = curl_easy_perform(curl);
    std::cout << "FFF" << std::endl;
    if(res == CURLE_OK) {
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      std::cout << "Responce code of https://google.ru "<< response_code << std::endl;
    }
    curl_easy_cleanup(curl);
  }
}

