<?php

namespace shopndrop_protocol;


// includes
require_once 'protocol.php';
require_once 'dummy_creator.php';
require_once 'html_helper.php';

# objects

function example_ProductItem()
{
    $obj = \shopndrop_protocol\create_dummy__ProductItem();

    echo "ProductItem : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_ShoppingItem()
{
    $obj = \shopndrop_protocol\create_dummy__ShoppingItem();

    echo "ShoppingItem : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_ShoppingList()
{
    $obj = \shopndrop_protocol\create_dummy__ShoppingList();

    echo "ShoppingList : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_GeoPosition()
{
    $obj = \shopndrop_protocol\create_dummy__GeoPosition();

    echo "GeoPosition : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_RideSummary()
{
    $obj = \shopndrop_protocol\create_dummy__RideSummary();

    echo "RideSummary : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_Ride()
{
    $obj = \shopndrop_protocol\create_dummy__Ride();

    echo "Ride : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_Address()
{
    $obj = \shopndrop_protocol\create_dummy__Address();

    echo "Address : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_Order()
{
    $obj = \shopndrop_protocol\create_dummy__Order();

    echo "Order : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}


# messages

function example_AddRideRequest()
{
    $obj = \shopndrop_protocol\create_dummy__AddRideRequest();

    echo "AddRideRequest : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_AddRideResponse()
{
    $obj = \shopndrop_protocol\create_dummy__AddRideResponse();

    echo "AddRideResponse : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_CancelRideRequest()
{
    $obj = \shopndrop_protocol\create_dummy__CancelRideRequest();

    echo "CancelRideRequest : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_CancelRideResponse()
{
    $obj = \shopndrop_protocol\create_dummy__CancelRideResponse();

    echo "CancelRideResponse : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetRideRequest()
{
    $obj = \shopndrop_protocol\create_dummy__GetRideRequest();

    echo "GetRideRequest : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetRideResponse()
{
    $obj = \shopndrop_protocol\create_dummy__GetRideResponse();

    echo "GetRideResponse : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_AddOrderRequest()
{
    $obj = \shopndrop_protocol\create_dummy__AddOrderRequest();

    echo "AddOrderRequest : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_AddOrderResponse()
{
    $obj = \shopndrop_protocol\create_dummy__AddOrderResponse();

    echo "AddOrderResponse : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_CancelOrderRequest()
{
    $obj = \shopndrop_protocol\create_dummy__CancelOrderRequest();

    echo "CancelOrderRequest : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_CancelOrderResponse()
{
    $obj = \shopndrop_protocol\create_dummy__CancelOrderResponse();

    echo "CancelOrderResponse : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_AcceptOrderRequest()
{
    $obj = \shopndrop_protocol\create_dummy__AcceptOrderRequest();

    echo "AcceptOrderRequest : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_AcceptOrderResponse()
{
    $obj = \shopndrop_protocol\create_dummy__AcceptOrderResponse();

    echo "AcceptOrderResponse : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_DeclineOrderRequest()
{
    $obj = \shopndrop_protocol\create_dummy__DeclineOrderRequest();

    echo "DeclineOrderRequest : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_DeclineOrderResponse()
{
    $obj = \shopndrop_protocol\create_dummy__DeclineOrderResponse();

    echo "DeclineOrderResponse : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_MarkDeliveredOrderRequest()
{
    $obj = \shopndrop_protocol\create_dummy__MarkDeliveredOrderRequest();

    echo "MarkDeliveredOrderRequest : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_MarkDeliveredOrderResponse()
{
    $obj = \shopndrop_protocol\create_dummy__MarkDeliveredOrderResponse();

    echo "MarkDeliveredOrderResponse : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_RateShopperRequest()
{
    $obj = \shopndrop_protocol\create_dummy__RateShopperRequest();

    echo "RateShopperRequest : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
}

function example_RateShopperResponse()
{
    $obj = \shopndrop_protocol\create_dummy__RateShopperResponse();

    echo "RateShopperResponse : HTML : " . \shopndrop_protocol\to_html( $obj ) . "<br>\n";
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
