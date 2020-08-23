<?php

namespace shopndrop_protocol;


// includes
require_once 'protocol.php';
require_once 'dummy_creator.php';
require_once 'str_helper.php';
require_once 'request_encoder.php';

# objects

function example_ProductItem()
{
    $obj = \shopndrop_protocol\create_dummy__ProductItem();

    echo "ProductItem : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";
}

function example_ShoppingItem()
{
    $obj = \shopndrop_protocol\create_dummy__ShoppingItem();

    echo "ShoppingItem : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";
}

function example_ShoppingList()
{
    $obj = \shopndrop_protocol\create_dummy__ShoppingList();

    echo "ShoppingList : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";
}

function example_GeoPosition()
{
    $obj = \shopndrop_protocol\create_dummy__GeoPosition();

    echo "GeoPosition : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";
}

function example_RideSummary()
{
    $obj = \shopndrop_protocol\create_dummy__RideSummary();

    echo "RideSummary : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";
}

function example_Ride()
{
    $obj = \shopndrop_protocol\create_dummy__Ride();

    echo "Ride : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";
}

function example_Address()
{
    $obj = \shopndrop_protocol\create_dummy__Address();

    echo "Address : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";
}

function example_Order()
{
    $obj = \shopndrop_protocol\create_dummy__Order();

    echo "Order : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";
}


# messages

function example_AddRideRequest()
{
    $obj = \shopndrop_protocol\create_dummy__AddRideRequest();

    echo "AddRideRequest : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "AddRideRequest : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_AddRideResponse()
{
    $obj = \shopndrop_protocol\create_dummy__AddRideResponse();

    echo "AddRideResponse : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "AddRideResponse : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_CancelRideRequest()
{
    $obj = \shopndrop_protocol\create_dummy__CancelRideRequest();

    echo "CancelRideRequest : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "CancelRideRequest : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_CancelRideResponse()
{
    $obj = \shopndrop_protocol\create_dummy__CancelRideResponse();

    echo "CancelRideResponse : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "CancelRideResponse : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetRideRequest()
{
    $obj = \shopndrop_protocol\create_dummy__GetRideRequest();

    echo "GetRideRequest : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "GetRideRequest : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetRideResponse()
{
    $obj = \shopndrop_protocol\create_dummy__GetRideResponse();

    echo "GetRideResponse : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "GetRideResponse : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_AddOrderRequest()
{
    $obj = \shopndrop_protocol\create_dummy__AddOrderRequest();

    echo "AddOrderRequest : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "AddOrderRequest : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_AddOrderResponse()
{
    $obj = \shopndrop_protocol\create_dummy__AddOrderResponse();

    echo "AddOrderResponse : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "AddOrderResponse : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_CancelOrderRequest()
{
    $obj = \shopndrop_protocol\create_dummy__CancelOrderRequest();

    echo "CancelOrderRequest : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "CancelOrderRequest : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_CancelOrderResponse()
{
    $obj = \shopndrop_protocol\create_dummy__CancelOrderResponse();

    echo "CancelOrderResponse : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "CancelOrderResponse : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_AcceptOrderRequest()
{
    $obj = \shopndrop_protocol\create_dummy__AcceptOrderRequest();

    echo "AcceptOrderRequest : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "AcceptOrderRequest : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_AcceptOrderResponse()
{
    $obj = \shopndrop_protocol\create_dummy__AcceptOrderResponse();

    echo "AcceptOrderResponse : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "AcceptOrderResponse : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_DeclineOrderRequest()
{
    $obj = \shopndrop_protocol\create_dummy__DeclineOrderRequest();

    echo "DeclineOrderRequest : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "DeclineOrderRequest : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_DeclineOrderResponse()
{
    $obj = \shopndrop_protocol\create_dummy__DeclineOrderResponse();

    echo "DeclineOrderResponse : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "DeclineOrderResponse : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_MarkDeliveredOrderRequest()
{
    $obj = \shopndrop_protocol\create_dummy__MarkDeliveredOrderRequest();

    echo "MarkDeliveredOrderRequest : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "MarkDeliveredOrderRequest : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_MarkDeliveredOrderResponse()
{
    $obj = \shopndrop_protocol\create_dummy__MarkDeliveredOrderResponse();

    echo "MarkDeliveredOrderResponse : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "MarkDeliveredOrderResponse : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_RateShopperRequest()
{
    $obj = \shopndrop_protocol\create_dummy__RateShopperRequest();

    echo "RateShopperRequest : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "RateShopperRequest : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}

function example_RateShopperResponse()
{
    $obj = \shopndrop_protocol\create_dummy__RateShopperResponse();

    echo "RateShopperResponse : STR : " . \shopndrop_protocol\to_string( $obj ) . "\n";

    echo "RateShopperResponse : REQ : " . \shopndrop_protocol\to_generic_request( $obj ) . "\n";

}


{
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

}

# namespace_end shopndrop_protocol


?>
