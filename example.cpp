#include <iostream>

#include "generic_request/request_parser.h"

#include "shopndrop_protocol.h"
#include "request_parser.h"
#include "response_gen.h"           // create_AddRideResponse
#include "str_helper.h"             // StrHelper::to_string()
#include "csv_response_encoder.h"   // CsvResponseEncoder::to_csv()

void test( const std::string & str )
{
    std::cout << "REQ = " << str << " - ";

    try
    {
        auto gr = generic_request::RequestParser::to_request( str );

        auto * r = shopndrop_protocol::web::RequestParser::to_forward_message( gr );

        delete r;

        std::cout << "ok\n";
    }
    catch( std::exception & e )
    {
        std::cout << "FAILED - " << e.what() << "\n";
    }
}

void test_AddRideResponse()
{
    auto * s = shopndrop_protocol::create_AddRideResponse(
            123 );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( * s ) << std::endl;

    delete s;
}

void test_CancelRideResponse()
{
    auto s = shopndrop_protocol::create_CancelRideResponse();

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetRideResponse()
{
    shopndrop_protocol::Ride ride;

    shopndrop_protocol::init_Ride( & ride, { 50668, 0, 0 }, { 2019, 05, 22, 18, 0, 0 }, 2.0 );

    auto s = shopndrop_protocol::create_GetRideResponse( ride );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetPersonalUserInfoResponse()
{
    auto s = shopndrop_protocol::create_GetPersonalUserInfoResponse( 123,
            shopndrop_protocol::gender_e::MALE,
            "John", "Doe", "Yoyodine Corp.", "john.doe@yoyodine.com", "+491234567890", "Europe/Berlin" );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_AddOrderResponse()
{
    auto s = shopndrop_protocol::create_AddOrderResponse( 123 );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_CancelOrderResponse()
{
    auto s = shopndrop_protocol::create_CancelOrderResponse();

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetProductItemListResponse()
{
    std::vector<shopndrop_protocol::web::ProductItemWithId> pids  =
    {
            { 121212, { "Milch",    "Packung",  1.09, 1.0 } },
            { 232323, { "Brot",     "Stück",    1.49, 0.5 } },
            { 343434, { "Apfel",    "kg",       2.49, 1.5 } },
            { 454545, { "Nutella",  "Dose",     1.99, 0.3 } },
    };

    auto s = shopndrop_protocol::web::create_GetProductItemListResponse( pids );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetDeliveryRequestInfoResponse()
{
    std::vector<shopndrop_protocol::web::DeliveryRequestInfo> pids  =
    {
            { 121212, 10.35,    ( 10.35 / 1.3 ) * .15,  2.0, { 50668, "Germany", "Köln", "Eigelstein", "1", "" } },
            { 232323, 7.62,     ( 7.62 / 1.3 ) * .15,   2.7, { 50667, "Germany", "Köln", "Hohe Strasse", "17", "" } },
            { 343434, 12.67,    ( 12.67 / 1.3 ) * .15,  1.5, { 50672, "Germany", "Köln", "Antwerpener Strasse", "25", "" } },
            { 454545, 20.39,    ( 20.39 / 1.3 ) * .15,  1.0, { 50674, "Germany", "Köln", "Lindenstrasse", "56", "" } },
    };

    auto s = shopndrop_protocol::web::create_GetDeliveryRequestInfoResponse( pids );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetShoppingListWithTotalsResponse()
{
    std::vector<shopndrop_protocol::web::ShoppingItemWithProduct> shop_list_prod_items  =
    {
            { { 121212, 3 }, { "Milch",    "Packung",  1.09, 1.0 } },
            { { 232323, 2 }, { "Brot",     "Stück",    1.49, 0.5 } },
            { { 343434, 1 }, { "Apfel",    "kg",       2.49, 1.5 } },
            { { 454545, 1 }, { "Nutella",  "Dose",     1.99, 0.3 } },
    };

    shopndrop_protocol::web::ShoppingListWithTotals sl =
    {
            { shop_list_prod_items },
            10.73,
            5.8
    };

    auto s = shopndrop_protocol::web::create_GetShoppingListWithTotalsResponse( sl );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetDashScreenUserResponse()
{
    using namespace shopndrop_protocol;

    std::vector<web::RideWithShopper>      rides    =
    {
            { 121212, { { 50668, 0, 0 }, { 2019, 5, 22, 17, 30, 0 }, 3.0 }, "Matthias Mayer" },
            { 232323, { { 50667, 0, 0 }, { 2019, 5, 22, 19, 45, 0 }, 1.0 }, "Lukas Himmelfarb" },
            { 343434, { { 50672, 0, 0 }, { 2019, 5, 22, 23, 10, 0 }, 2.5 }, "Jonas Peschka" },
            { 454545, { { 50667, 0, 0 }, { 2019, 5, 23, 9, 0, 0 },   1.5 }, "Anke Rittermeyer" },
    };

    std::vector<web::AcceptedOrderUser>    orders   =
    {
            { 565656, { false,  { 2019, 3, 27, 20, 20, 0 }, { 50668, "Germany", "Köln", "Eigelstein", "1", "" },        141414, order_state_e::UNDEF, order_resolution_e::DELIVERED }, 17.25, "Liam Hoffman" },
            { 676767, { false,  { 2019, 5, 22, 17, 30, 0 }, { 50667, "Germany", "Köln", "Hohe Strasse", "17", "" },     252525, order_state_e::UNDEF, order_resolution_e::RIDE_CANCELLED }, 17.25, "Julian Koch" },
            { 787878, { true,   { 2019, 5, 27, 20, 20, 0 }, { 50672, "Germany", "Köln", "Antwerpener Strasse", "25", "" }, 363636, order_state_e::DELIVERED_WAITING_FEEDBACK, order_resolution_e::UNDEF }, 17.25, "Tim Bauer" },
            { 898989, { true,   { 2019, 5, 29, 18, 45, 0 }, { 50674, "Germany", "Köln", "Lindenstrasse", "56", "" },    474747, order_state_e::ACCEPTED_WAITING_DELIVERY, order_resolution_e::UNDEF }, 17.25, "Elias Wolf" },
            { 909090, { true,   { 2019, 5, 30, 19, 30, 0 }, { 50674, "Germany", "Köln", "Roonnstrasse", "29", "" },     585858, order_state_e::IDLE_WAITING_ACCEPTANCE, order_resolution_e::UNDEF }, 17.25, "Michael Schröder" },
    };

    web::DashScreenUser c;

    web::init_DashScreenUser( & c, { 2019, 5, 22, 17, 30, 0 }, rides, orders );

    auto s = web::create_GetDashScreenUserResponse( c );

    std::cout << CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetDashScreenShopperResponse()
{
    using namespace shopndrop_protocol;

    std::vector<web::RideWithRequests>      rides    =
    {
            { 121212, { { 50668, 0, 0 }, { 2019, 5, 22, 17, 30, 0 }, 3.0 }, 2 },
            { 232323, { { 50667, 0, 0 }, { 2019, 5, 22, 19, 45, 0 }, 1.0 }, 1 },
            { 343434, { { 50672, 0, 0 }, { 2019, 5, 22, 23, 10, 0 }, 2.5 }, 1 },
            { 454545, { { 50667, 0, 0 }, { 2019, 5, 23, 9, 0, 0 },   1.5 }, 1 },
    };

    std::vector<web::AcceptedOrderShopper>    orders   =
    {
            { 565656, { false, { 2019, 3, 27, 20, 20, 0 }, { 50668, "Germany", "Köln", "Eigelstein", "1", "" },        141414, order_state_e::UNDEF, order_resolution_e::DELIVERED }, 17.25, 1.12, 2.0 },
            { 676767, { false, { 2019, 5, 22, 17, 30, 0 }, { 50667, "Germany", "Köln", "Hohe Strasse", "17", "" },     252525, order_state_e::UNDEF, order_resolution_e::RIDE_CANCELLED }, 23.39, 2.5, 1.5 },
            { 787878, { true,  { 2019, 5, 27, 20, 20, 0 }, { 50672, "Germany", "Köln", "Antwerpener Strasse", "25", "" }, 363636, order_state_e::DELIVERED_WAITING_FEEDBACK, order_resolution_e::UNDEF }, 11.87, 1.12, .5 },
            { 898989, { true,  { 2019, 5, 29, 18, 45, 0 }, { 50674, "Germany", "Köln", "Lindenstrasse", "56", "" },    474747, order_state_e::ACCEPTED_WAITING_DELIVERY, order_resolution_e::UNDEF }, 20.15, 2.02, 1.2 },
            { 909090, { true,  { 2019, 5, 30, 19, 30, 0 }, { 50674, "Germany", "Köln", "Roonnstrasse", "29", "" },     585858, order_state_e::IDLE_WAITING_ACCEPTANCE, order_resolution_e::UNDEF }, 23.20, 2.3, 1.7 },
    };

    web::DashScreenShopper c;

    web::init_DashScreenShopper( & c, { 2019, 5, 22, 17, 30, 0 }, rides, orders );

    auto s = web::create_GetDashScreenShopperResponse( c );

    std::cout << CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

int main()
{
    test_AddRideResponse();
    test_CancelRideResponse();

    test_GetRideResponse();

    test_GetPersonalUserInfoResponse();

    test_AddOrderResponse();
    test_CancelOrderResponse();
    test_GetProductItemListResponse();
    test_GetDeliveryRequestInfoResponse();
    test_GetShoppingListWithTotalsResponse();
    test_GetDashScreenUserResponse();
    test_GetDashScreenShopperResponse();

    std::cout << "\n*********************************\n" << std::endl;

    test( "CMD=AddOrderRequest&RIDE_ID=&SHOPPING_LIST=1,1&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=0&SHOPPING_LIST=1,1&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );

    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=0,0&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=0,1&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,0&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1,0&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1,1&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1,1,0&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1,0,1&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1,1,1&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );

    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1&PLZ=&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1&PLZ=0&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1&PLZ=11111&COUNTRY=&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1&PLZ=11111&COUNTRY=Germany&CITY=&STREET=Oststr.&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=&HOUSE_NUMBER=10&EAL=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1&PLZ=11111&COUNTRY=Germany&CITY=Cologne&STREET=Oststr.&HOUSE_NUMBER=&EAL=&SESSION_ID=afafaf" );

    test( "CMD=AddRideRequest&PLZ=&DELIVERY_TIME=20190522173000&MAX_WEIGHT=1.5&SESSION_ID=afafaf" );
    test( "CMD=AddRideRequest&PLZ=0&DELIVERY_TIME=20190522173000&MAX_WEIGHT=1.5&SESSION_ID=afafaf" );
    test( "CMD=AddRideRequest&PLZ=1&DELIVERY_TIME=20190522173000&MAX_WEIGHT=1.5&SESSION_ID=afafaf" );
    test( "CMD=AddRideRequest&PLZ=1&DELIVERY_TIME=&MAX_WEIGHT=1.5&SESSION_ID=afafaf" );
    test( "CMD=AddRideRequest&PLZ=1&DELIVERY_TIME=0&MAX_WEIGHT=1.5&SESSION_ID=afafaf" );
    test( "CMD=AddRideRequest&PLZ=1&DELIVERY_TIME=20190522173000&MAX_WEIGHT=1.5&SESSION_ID=afafaf" );
    test( "CMD=AddRideRequest&PLZ=1&DELIVERY_TIME=20190522173000&MAX_WEIGHT=&SESSION_ID=afafaf" );
    test( "CMD=AddRideRequest&PLZ=1&DELIVERY_TIME=20190522173000&MAX_WEIGHT=0&SESSION_ID=afafaf" );
    test( "CMD=AddRideRequest&PLZ=1&DELIVERY_TIME=20190522173000&MAX_WEIGHT=1.5&SESSION_ID=afafaf" );

    test( "CMD=CancelOrderRequest&ORDER_ID=&&SESSION_ID=afafaf" );
    test( "CMD=CancelOrderRequest&ORDER_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=CancelOrderRequest&ORDER_ID=1&&SESSION_ID=afafaf" );

    test( "CMD=CancelRideRequest&RIDE_ID=&&SESSION_ID=afafaf" );
    test( "CMD=CancelRideRequest&RIDE_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=CancelRideRequest&RIDE_ID=1&&SESSION_ID=afafaf" );

    test( "CMD=GetRideRequest&RIDE_ID=&&SESSION_ID=afafaf" );
    test( "CMD=GetRideRequest&RIDE_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=GetRideRequest&RIDE_ID=1&&SESSION_ID=afafaf" );

    test( "CMD=GetPersonalUserInfoRequest&USER_ID=&&SESSION_ID=afafaf" );
    test( "CMD=GetPersonalUserInfoRequest&USER_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=GetPersonalUserInfoRequest&USER_ID=1&&SESSION_ID=afafaf" );

    test( "CMD=web/GetProductItemListRequest&SESSION_ID=afafaf" );

    test( "CMD=web/GetDeliveryRequestInfoRequest&RIDE_ID=&&SESSION_ID=afafaf" );
    test( "CMD=web/GetDeliveryRequestInfoRequest&RIDE_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=web/GetDeliveryRequestInfoRequest&RIDE_ID=1&&SESSION_ID=afafaf" );

    test( "CMD=web/GetShoppingListWithTotalsRequest&SHOPPING_LIST_ID=&&SESSION_ID=afafaf" );
    test( "CMD=web/GetShoppingListWithTotalsRequest&SHOPPING_LIST_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=web/GetShoppingListWithTotalsRequest&SHOPPING_LIST_ID=1&&SESSION_ID=afafaf" );

    test( "CMD=web/GetDashScreenUserRequest&USER_ID=&&SESSION_ID=afafaf" );
    test( "CMD=web/GetDashScreenUserRequest&USER_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=web/GetDashScreenUserRequest&USER_ID=1&&SESSION_ID=afafaf" );

    test( "CMD=web/GetDashScreenShopperRequest&USER_ID=&&SESSION_ID=afafaf" );
    test( "CMD=web/GetDashScreenShopperRequest&USER_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=web/GetDashScreenShopperRequest&USER_ID=1&&SESSION_ID=afafaf" );

    return 0;
}
