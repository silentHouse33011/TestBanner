#include "Banner.h"

Banner::Banner(double price, unsigned int advertisingCompanyID, unsigned int internalID, std::vector<std::string> &countries) {

    SetPrice(price);
    SetAdvertisingCompanyID(advertisingCompanyID);
    SetInternalID(internalID);
    SetCountryList(countries);
}

Banner::~Banner() {

}

void Banner::PrintBannerInfo() {

    std::cout <<  "Price : " << this->_Price << std::endl;

    std::cout << "Countries : " << std::endl;


    if (this->GetCountryList().empty()) {

        std::cout << "Any country ";
    }
    else {

        for (const auto country : this->_CountryList) {

            std::cout << country << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "Internal ID " << this->_InternalID << std::endl;
    std::cout << "External ID " << this->_AdvertisingCompanyID << std::endl << std::endl;
}

void Banner::SetCountryList(const std::vector<std::string>& countries) {

    this->_CountryList = countries;
}

std::vector<std::string> Banner::GetCountryList() const {

    return this->_CountryList;
}

void Banner::SetPrice(const double& price) {

    this->_Price = price;
}
void Banner::SetAdvertisingCompanyID(const unsigned int& id) {

    this->_AdvertisingCompanyID = id;
}
void Banner::SetInternalID(const unsigned int& id) {

    this->_InternalID = id;
}

double Banner::GetPrice() const {

    if (this->_Price < 0) {

        return 0.0;
    }

    return this->_Price;
}

unsigned int Banner::GetAdvertisingCompanyID() const {

    return this->_AdvertisingCompanyID;
}

unsigned int Banner::GetInternalID() const {

    return this->_InternalID;
}
