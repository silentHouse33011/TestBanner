#include "Auction.h"

Auction::~Auction() {

}

void Auction::AddBanner(const Banner& banner) {

	this->_SelectedBanners.emplace_back(banner);
}

void Auction::SetFiltersFunctions(std::vector<std::function<bool(const Banner&)>> filterFunction) {

	this->filterFunctions = filterFunction;
}

std::vector<Banner> Auction::GetBanners() const {

	return this->_SelectedBanners;
}

bool Auction::CheckCountry(std::vector<std::string> bannersCuntryList, std::string& country) {

	if (std::find(bannersCuntryList.begin(), bannersCuntryList.end(), country) != bannersCuntryList.end()) {
		return true;
	}
	return false;
}

bool Auction::checkFilters(const Banner& banner) {

	for (auto filter : filterFunctions) {
		if (!filter(banner)) {
			return false;
		}
	}
	return true;
}
bool Auction::CheckBannerId(const unsigned int& id) {

	if (std::find(_UniqueAdvIds.begin(), _UniqueAdvIds.end(), id) == _UniqueAdvIds.end()) {

		this->_UniqueAdvIds.emplace_back(id);
		return true;
	}

	return false;
}

std::vector<Banner> Auction::Auction::runAuction(const std::vector<Banner> &banners, int slots, std::string country,
												 std::vector<std::function<bool(const Banner &)>> filterFunctions) {

	SetFiltersFunctions(filterFunctions);

	int slotsCounter = 0;

	std::vector<Banner> sortedBanners = banners;

	std::sort(sortedBanners.begin(), sortedBanners.end(), [&](Banner &b1, Banner& b2) {
											      return b1.GetPrice() > b2.GetPrice();});

	for (const Banner& banner : sortedBanners) {

		//Default FilterPaass state
		bool FilterPassed = true;

		//Check for advertising slots
		if (slotsCounter < slots) {

			std::vector<std::string> BannerCountries = banner.GetCountryList();

			//Check Filters
			FilterPassed = checkFilters(banner);
				//Check Country 
			if (!BannerCountries.empty()) {

				if (CheckCountry(banner.GetCountryList(), country)) {

					//Check Id
					if (CheckBannerId(banner.GetAdvertisingCompanyID()) && FilterPassed) {

						AddBanner(banner);
						slotsCounter++;
					}
				}
			}
			else {
				//If countries is empty (Any country)

				if (FilterPassed) {

					if (CheckBannerId(banner.GetAdvertisingCompanyID())) {

						AddBanner(banner);
						slotsCounter++;
					}
				}
			}
		}
	}

	return this->GetBanners();
}