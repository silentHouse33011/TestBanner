#pragma once

#include "Banner.h"
#include <algorithm>
#include <vector>
#include <functional>
class Auction {

public:

	Auction() {};

	~Auction();

	std::vector<Banner> runAuction(const std::vector<Banner> &banners, int slots, std::string country, 
								   std::vector<std::function<bool(const Banner&)>> filterFunction = {});

	void AddBanner(const Banner& banner);

	bool CheckBannerId(const unsigned int& id);

	bool CheckCountry(std::vector<std::string> bannersCuntryList, std::string& country);

	bool checkFilters(const Banner& banner);

	std::vector<Banner> GetBanners() const;

	void SetFiltersFunctions(std::vector<std::function<bool(const Banner&)>> filterFunction);

private:

	std::vector<Banner> _SelectedBanners;

	std::vector<unsigned int> _UniqueAdvIds;

	std::vector<std::function<bool(const Banner&)>> filterFunctions;

};