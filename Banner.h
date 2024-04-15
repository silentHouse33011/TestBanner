#pragma once
#include <vector>
#include <string>
#include <iostream>

class Banner
{
public:

    Banner() {};

    ~Banner();

    void PrintBannerInfo();
    Banner(double price, unsigned int AdvertisingCompanyID, unsigned int InternalID, std::vector<std::string> &countries);

    void SetPrice(const double& price);
    void SetAdvertisingCompanyID(const unsigned int& id);
    void SetInternalID(const unsigned int& id);
    void SetCountryList(const std::vector<std::string>& countries);

    double GetPrice() const;
    unsigned int GetInternalID() const;
    unsigned int GetAdvertisingCompanyID() const;
    
    std::vector<std::string> GetCountryList() const;

private:

    double _Price;
    unsigned int _InternalID;
    unsigned int _AdvertisingCompanyID;

    std::vector<std::string> _CountryList;
};