#pragma once

#include <iostream>
#include "Auction.h"
#include "TESTS.h"

using namespace std;

int main()
{
	std::vector<std::string> countriesTest{ "USA", "Russia", "Japan" };

	Banner b1(30.5, 3, 3, countriesTest);
	Banner b2(10, 10, 1, countriesTest);
	Banner b3(30, 1, 4, countriesTest);
	Banner b4(40, 2, 5, countriesTest);

	//Banner with empty country list
	Banner b5(100, 4, 2, std::vector<std::string> {});

	std::vector<Banner> bannersList { b1, b2, b3, b4, b5 };

	Auction testAuction;

	std::vector<Banner> PlacedBanners;

	//Filter as lambda fucntion 
	//U can create any filter for any field of banner exmaple with price
	auto priceFilter = [](const Banner& banner) {

		return banner.GetPrice() > 30;
	};

	std::vector<std::function<bool(const Banner&)>> filters{ priceFilter };
	
	PlacedBanners = testAuction.runAuction(bannersList, 1, "USA", filters);

	for (auto &baner : PlacedBanners) {

		baner.PrintBannerInfo();
	}

	RUN_TESTS();

	return 0;
}
