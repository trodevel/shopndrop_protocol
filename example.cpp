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
            { 121212, { "Brot",     "Stück",    1.49, 0.5 } },
            { 121212, { "Apfel",    "kg",       2.49, 1.5 } },
            { 121212, { "Nutella",  "Dose",     1.99, 0.3 } },
    };

    auto s = shopndrop_protocol::web::create_GetProductItemListResponse( pids );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetRideOrderInfoResponse()
{
    std::vector<shopndrop_protocol::web::OrderRequestInfo> pids  =
    {
            { 121212, 10.35,    ( 10.35 / 1.3 ) * .15,  2.0, { 50668, 0, 0 }, "Eigelstein 1" },
            { 232323, 7.62,     ( 7.62 / 1.3 ) * .15,   2.7, { 50667, 0, 0 }, "Hohe Strasse 17" },
            { 121212, 12.67,    ( 12.67 / 1.3 ) * .15,  1.5, { 50672, 0, 0 }, "Antwerpener Strasse 25" },
            { 121212, 20.39,    ( 20.39 / 1.3 ) * .15,  1.0, { 50674, 0, 0 }, "Lindenstrasse 56" },
    };

    auto s = shopndrop_protocol::web::create_GetRideOrderInfoResponse( pids );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetDashScreenUserResponse()
{
    std::vector<shopndrop_protocol::web::RideWithShopper>      rides    =
    {
            { 121212, { { 50668, 0, 0 }, { 2019, 5, 22, 17, 30, 0 }, 3.0 }, "Matthias Mayer" },
            { 232323, { { 50667, 0, 0 }, { 2019, 5, 22, 19, 45, 0 }, 1.0 }, "Lukas Himmelfarb" },
            { 343434, { { 50672, 0, 0 }, { 2019, 5, 22, 23, 10, 0 }, 2.5 }, "Jonas Peschka" },
            { 454545, { { 50667, 0, 0 }, { 2019, 5, 23, 9, 0, 0 },   1.5 }, "Anke Rittermeyer" },
    };

    std::vector<shopndrop_protocol::web::AcceptedOrderUser>    orders   =
    {
            { 565656, { { 2019, 3, 27, 20, 20, 0 }, 141414, 17.25, shopndrop_protocol::order_status_e::CLOSED_FEEDBACK_RECEIVED }, "Liam Hoffman" },
            { 676767, { { 2019, 5, 22, 17, 30, 0 }, 252525, 17.25, shopndrop_protocol::order_status_e::CANCELLED }, "Julian Koch" },
            { 787878, { { 2019, 5, 27, 20, 20, 0 }, 363636, 17.25, shopndrop_protocol::order_status_e::DELIVERED_WAITING_FEEDBACK }, "Tim Bauer" },
            { 898989, { { 2019, 5, 29, 18, 45, 0 }, 474747, 17.25, shopndrop_protocol::order_status_e::ACCEPTED_WAITING_DELIVERY }, "Elias Wolf" },
            { 909090, { { 2019, 5, 30, 19, 30, 0 }, 585858, 17.25, shopndrop_protocol::order_status_e::WAITING_ACCEPTANCE }, "Michael Schröder" },
    };

    shopndrop_protocol::web::DashScreenUser c;

    shopndrop_protocol::web::init_DashScreenUser( & c, { 2019, 5, 22, 17, 30, 0 }, rides, orders );

    auto s = shopndrop_protocol::web::create_GetDashScreenUserResponse( c );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetDashScreenShopperResponse()
{
    std::vector<shopndrop_protocol::web::RideWithRequests>      rides    =
    {
            { 121212, { { 50668, 0, 0 }, { 2019, 5, 22, 17, 30, 0 }, 3.0 }, 2 },
            { 232323, { { 50667, 0, 0 }, { 2019, 5, 22, 19, 45, 0 }, 1.0 }, 1 },
            { 343434, { { 50672, 0, 0 }, { 2019, 5, 22, 23, 10, 0 }, 2.5 }, 1 },
            { 454545, { { 50667, 0, 0 }, { 2019, 5, 23, 9, 0, 0 },   1.5 }, 1 },
    };

    std::vector<shopndrop_protocol::web::AcceptedOrderShopper>    orders   =
    {
            { 565656, { { 2019, 3, 27, 20, 20, 0 }, 141414, 17.25, shopndrop_protocol::order_status_e::CLOSED_FEEDBACK_RECEIVED }, { 50668, 0, 0 }, "Eigelstein 1", 1.12, 2.0 },
            { 676767, { { 2019, 5, 22, 17, 30, 0 }, 252525, 23.39, shopndrop_protocol::order_status_e::CANCELLED }, { 50667, 0, 0 }, "Hohe Strasse 17", 2.5, 1.5 },
            { 787878, { { 2019, 5, 27, 20, 20, 0 }, 363636, 11.87, shopndrop_protocol::order_status_e::DELIVERED_WAITING_FEEDBACK }, { 50672, 0, 0 }, "Antwerpener Strasse 25", 1.12, .5 },
            { 898989, { { 2019, 5, 29, 18, 45, 0 }, 474747, 20.15, shopndrop_protocol::order_status_e::ACCEPTED_WAITING_DELIVERY }, { 50674, 0, 0 }, "Lindenstrasse 56", 2.02, 1.2 },
            { 909090, { { 2019, 5, 30, 19, 30, 0 }, 585858, 23.20, shopndrop_protocol::order_status_e::WAITING_ACCEPTANCE }, { 50674, 0, 0 }, "Roonnstrasse 29", 2.3, 1.7 },
    };

    shopndrop_protocol::web::DashScreenShopper c;

    shopndrop_protocol::web::init_DashScreenShopper( & c, { 2019, 5, 22, 17, 30, 0 }, rides, orders );

    auto s = shopndrop_protocol::web::create_GetDashScreenShopperResponse( c );

    std::cout << shopndrop_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

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
    test_GetRideOrderInfoResponse();
    test_GetDashScreenUserResponse();
    test_GetDashScreenShopperResponse();

    std::cout << "\n*********************************\n" << std::endl;

    test( "CMD=AddOrderRequest&RIDE_ID=&SHOPPING_LIST=1,1&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=0&SHOPPING_LIST=1,1&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1&SESSION_ID=afafaf" );

    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=0,0&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=0,1&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,0&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1,0&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1,1&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1,1,0&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1,0,1&SESSION_ID=afafaf" );
    test( "CMD=AddOrderRequest&RIDE_ID=1&SHOPPING_LIST=1,1,1,1&SESSION_ID=afafaf" );

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

    test( "CMD=web/GetRideOrderInfoRequest&RIDE_ID=&&SESSION_ID=afafaf" );
    test( "CMD=web/GetRideOrderInfoRequest&RIDE_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=web/GetRideOrderInfoRequest&RIDE_ID=1&&SESSION_ID=afafaf" );

    test( "CMD=web/GetDashScreenUserRequest&USER_ID=&&SESSION_ID=afafaf" );
    test( "CMD=web/GetDashScreenUserRequest&USER_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=web/GetDashScreenUserRequest&USER_ID=1&&SESSION_ID=afafaf" );

    test( "CMD=web/GetDashScreenShopperRequest&USER_ID=&&SESSION_ID=afafaf" );
    test( "CMD=web/GetDashScreenShopperRequest&USER_ID=0&&SESSION_ID=afafaf" );
    test( "CMD=web/GetDashScreenShopperRequest&USER_ID=1&&SESSION_ID=afafaf" );

    return 0;
}
