#include "protocol.h"
#include "str_helper.h"
#include "csv_helper.h"
#include "dummy_creator.h"
#include "validator.h"

#include <iostream>       // std::cout

template <class T>
void validate( const T & o, const std::string & name )
{
    try
    {
        shopndrop_protocol::validator::validate( o );
        std::cout << name << " : valid" << std::endl;
    }
    catch( std::exception & e )
    {
        std::cout << name << " : invalid : " << e.what() << std::endl;
    }
}

// enums

void example_ride_resolution_e()
{
    auto obj = shopndrop_protocol::dummy::create__ride_resolution_e();

    std::cout << "ride_resolution_e : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_order_resolution_e()
{
    auto obj = shopndrop_protocol::dummy::create__order_resolution_e();

    std::cout << "order_resolution_e : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_order_state_e()
{
    auto obj = shopndrop_protocol::dummy::create__order_state_e();

    std::cout << "order_state_e : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_gender_e()
{
    auto obj = shopndrop_protocol::dummy::create__gender_e();

    std::cout << "gender_e : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}


// objects

void example_ProductItem()
{
    auto obj = shopndrop_protocol::dummy::create__ProductItem();

    std::cout << "ProductItem : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ShoppingItem()
{
    auto obj = shopndrop_protocol::dummy::create__ShoppingItem();

    std::cout << "ShoppingItem : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ShoppingList()
{
    auto obj = shopndrop_protocol::dummy::create__ShoppingList();

    std::cout << "ShoppingList : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_GeoPosition()
{
    auto obj = shopndrop_protocol::dummy::create__GeoPosition();

    std::cout << "GeoPosition : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_RideSummary()
{
    auto obj = shopndrop_protocol::dummy::create__RideSummary();

    std::cout << "RideSummary : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_Ride()
{
    auto obj = shopndrop_protocol::dummy::create__Ride();

    std::cout << "Ride : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_Address()
{
    auto obj = shopndrop_protocol::dummy::create__Address();

    std::cout << "Address : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_Order()
{
    auto obj = shopndrop_protocol::dummy::create__Order();

    std::cout << "Order : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;
}


// messages

void example_AddRideRequest()
{
    auto & obj = * shopndrop_protocol::dummy::create__AddRideRequest();

    std::cout << "AddRideRequest : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AddRideRequest : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AddRideRequest" );

    delete & obj;
}

void example_AddRideResponse()
{
    auto & obj = * shopndrop_protocol::dummy::create__AddRideResponse();

    std::cout << "AddRideResponse : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AddRideResponse : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AddRideResponse" );

    delete & obj;
}

void example_CancelRideRequest()
{
    auto & obj = * shopndrop_protocol::dummy::create__CancelRideRequest();

    std::cout << "CancelRideRequest : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "CancelRideRequest : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "CancelRideRequest" );

    delete & obj;
}

void example_CancelRideResponse()
{
    auto & obj = * shopndrop_protocol::dummy::create__CancelRideResponse();

    std::cout << "CancelRideResponse : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "CancelRideResponse : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "CancelRideResponse" );

    delete & obj;
}

void example_GetRideRequest()
{
    auto & obj = * shopndrop_protocol::dummy::create__GetRideRequest();

    std::cout << "GetRideRequest : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetRideRequest : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetRideRequest" );

    delete & obj;
}

void example_GetRideResponse()
{
    auto & obj = * shopndrop_protocol::dummy::create__GetRideResponse();

    std::cout << "GetRideResponse : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetRideResponse : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetRideResponse" );

    delete & obj;
}

void example_AddOrderRequest()
{
    auto & obj = * shopndrop_protocol::dummy::create__AddOrderRequest();

    std::cout << "AddOrderRequest : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AddOrderRequest : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AddOrderRequest" );

    delete & obj;
}

void example_AddOrderResponse()
{
    auto & obj = * shopndrop_protocol::dummy::create__AddOrderResponse();

    std::cout << "AddOrderResponse : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AddOrderResponse : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AddOrderResponse" );

    delete & obj;
}

void example_CancelOrderRequest()
{
    auto & obj = * shopndrop_protocol::dummy::create__CancelOrderRequest();

    std::cout << "CancelOrderRequest : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "CancelOrderRequest : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "CancelOrderRequest" );

    delete & obj;
}

void example_CancelOrderResponse()
{
    auto & obj = * shopndrop_protocol::dummy::create__CancelOrderResponse();

    std::cout << "CancelOrderResponse : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "CancelOrderResponse : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "CancelOrderResponse" );

    delete & obj;
}

void example_AcceptOrderRequest()
{
    auto & obj = * shopndrop_protocol::dummy::create__AcceptOrderRequest();

    std::cout << "AcceptOrderRequest : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AcceptOrderRequest : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AcceptOrderRequest" );

    delete & obj;
}

void example_AcceptOrderResponse()
{
    auto & obj = * shopndrop_protocol::dummy::create__AcceptOrderResponse();

    std::cout << "AcceptOrderResponse : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "AcceptOrderResponse : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "AcceptOrderResponse" );

    delete & obj;
}

void example_DeclineOrderRequest()
{
    auto & obj = * shopndrop_protocol::dummy::create__DeclineOrderRequest();

    std::cout << "DeclineOrderRequest : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "DeclineOrderRequest : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "DeclineOrderRequest" );

    delete & obj;
}

void example_DeclineOrderResponse()
{
    auto & obj = * shopndrop_protocol::dummy::create__DeclineOrderResponse();

    std::cout << "DeclineOrderResponse : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "DeclineOrderResponse : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "DeclineOrderResponse" );

    delete & obj;
}

void example_MarkDeliveredOrderRequest()
{
    auto & obj = * shopndrop_protocol::dummy::create__MarkDeliveredOrderRequest();

    std::cout << "MarkDeliveredOrderRequest : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "MarkDeliveredOrderRequest : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "MarkDeliveredOrderRequest" );

    delete & obj;
}

void example_MarkDeliveredOrderResponse()
{
    auto & obj = * shopndrop_protocol::dummy::create__MarkDeliveredOrderResponse();

    std::cout << "MarkDeliveredOrderResponse : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "MarkDeliveredOrderResponse : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "MarkDeliveredOrderResponse" );

    delete & obj;
}

void example_RateShopperRequest()
{
    auto & obj = * shopndrop_protocol::dummy::create__RateShopperRequest();

    std::cout << "RateShopperRequest : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "RateShopperRequest : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "RateShopperRequest" );

    delete & obj;
}

void example_RateShopperResponse()
{
    auto & obj = * shopndrop_protocol::dummy::create__RateShopperResponse();

    std::cout << "RateShopperResponse : STR : " << shopndrop_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "RateShopperResponse : CSV : " << shopndrop_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "RateShopperResponse" );

    delete & obj;
}


int main( int argc, char ** argv )
{
    if( argc > 1 )
    {
        std::srand( std::stoi( std::string( argv[1] ) ) );
    }

    // enums

    example_ride_resolution_e();
    example_order_resolution_e();
    example_order_state_e();
    example_gender_e();

    // objects

    example_ProductItem();
    example_ShoppingItem();
    example_ShoppingList();
    example_GeoPosition();
    example_RideSummary();
    example_Ride();
    example_Address();
    example_Order();

    // messages

    example_AddRideRequest();
    example_AddRideResponse();
    example_CancelRideRequest();
    example_CancelRideResponse();
    example_GetRideRequest();
    example_GetRideResponse();
    example_AddOrderRequest();
    example_AddOrderResponse();
    example_CancelOrderRequest();
    example_CancelOrderResponse();
    example_AcceptOrderRequest();
    example_AcceptOrderResponse();
    example_DeclineOrderRequest();
    example_DeclineOrderResponse();
    example_MarkDeliveredOrderRequest();
    example_MarkDeliveredOrderResponse();
    example_RateShopperRequest();
    example_RateShopperResponse();

    return 0;
}

