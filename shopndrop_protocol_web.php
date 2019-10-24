<?php

/*

Shopndrop Protocol messages. Web.

Copyright (C) 2019 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 11428 $ $Date:: 2019-05-15 #$ $Author: serge $

namespace shopndrop_protocol\web;

require_once __DIR__.'/../shopndrop_protocol/shopndrop_protocol.php';

/**************************************************
 * OBJECTS
 **************************************************/

class ProductItemWithId
{
    public  $product_item_id;   // id_t
    public  $product_item;      // ProductItem
}

class ShoppingItemWithProduct
{
    public  $shopping_item;     // ShoppingItem
    public  $product_item;      // ProductItem
}

class ShoppingListWithProduct
{
    public  $items;             // array<ShoppingItemWithProduct>
}

class ShoppingListWithTotals
{
    public  $shopping_list;     // ShoppingListWithProduct
    public  $price;             // double
    public  $weight;            // double
}

class RideSummaryWithShopper
{
    public  $ride_id;           // id_t
    public  $ride;              // RideSummary
    public  $shopper_name;      // string
}

class RideWithId
{
    public  $ride_id;           // id_t
    public  $ride;              // Ride
}

class ShoppingRequestInfo
{
    public  $order_id;          // id_t
    public  $sum;               // double
    public  $earning;           // double
    public  $weight;            // double
    public  $address;           // Address
}

class AcceptedOrderUser
{
    public  $order_id;          // id_t
    public  $delivery_time;     // basic_objects::LocalTime
    public  $order;             // Order
    public  $sum;               // double
    public  $shopper_name;      // string
}

class AcceptedOrderShopper
{
    public  $order_id;          // id_t
    public  $delivery_time;     // basic_objects::LocalTime
    public  $order;             // Order
    public  $sum;               // double
    public  $earning;           // double
    public  $weight;            // double
}

class DashScreenUser
{
    public  $current_time;      // basic_objects::LocalTime

    public  $rides;             // array<RideSummaryWithShopper>
    public  $orders;            // array<AcceptedOrderUser>
}

class DashScreenShopper
{
    public  $current_time;      // basic_objects::LocalTime

    public  $rides;             // array<RideWithId>
    public  $orders;            // array<AcceptedOrderShopper>
}

/**************************************************
 * REQUESTS
 **************************************************/

class GetProductItemListRequest extends \shopndrop_protocol\Request
{
    function __construct( $session_id )
    {
        parent::__construct( $session_id );
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "web/GetProductItemListRequest",
        );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
}

class GetProductItemListResponse extends \generic_protocol\BackwardMessage
{
    public  $product_items;     // array<ProductItemWithId>
}

class GetShoppingRequestInfoRequest extends \shopndrop_protocol\Request
{
    public  $ride_id;           // id_t

    function __construct( $session_id, $ride_id )
    {
        parent::__construct( $session_id );

        $this->ride_id      = $ride_id;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "web/GetShoppingRequestInfoRequest",
            "RIDE_ID"   => $this->ride_id
        );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
}

class GetShoppingRequestInfoResponse extends \generic_protocol\BackwardMessage
{
    public  $requests;          // array<ShoppingRequestInfo>
}

class GetShoppingListWithTotalsRequest extends \shopndrop_protocol\Request
{
    public  $shopping_list_id;  // id_t

    function __construct( $session_id, $shopping_list_id )
    {
        parent::__construct( $session_id );

        $this->shopping_list_id = $shopping_list_id;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"               => "web/GetShoppingListWithTotalsRequest",
            "SHOPPING_LIST_ID"  => $this->shopping_list_id
        );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
}

class GetShoppingListWithTotalsResponse extends \generic_protocol\BackwardMessage
{
    public  $shopping_list;     // ShoppingListWithTotals
}

class GetDashScreenUserRequest extends \shopndrop_protocol\Request
{
    public  $user_id;           // id_t
    public  $position;          // GeoPosition

    function __construct( $session_id, $user_id, $position )
    {
        parent::__construct( $session_id );

        $this->user_id      = $user_id;
        $this->position     = $position;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "web/GetDashScreenUserRequest",
            "USER_ID"   => $this->user_id
        );

        return \generic_protocol\assemble_request( $res ) .
            $this->position->to_generic_request() .
            parent::to_generic_request();
    }
}

class GetDashScreenUserResponse extends \generic_protocol\BackwardMessage
{
    public  $dash_screen;       // DashScreenUser
}

class GetDashScreenShopperRequest extends \shopndrop_protocol\Request
{
    public  $user_id;           // id_t
    public  $position;          // GeoPosition

    function __construct( $session_id, $user_id, $position )
    {
        parent::__construct( $session_id );

        $this->user_id      = $user_id;
        $this->position     = $position;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "web/GetDashScreenShopperRequest",
            "USER_ID"   => $this->user_id
        );

        return \generic_protocol\assemble_request( $res ) .
            $this->position->to_generic_request() .
            parent::to_generic_request();
    }
}

class GetDashScreenShopperResponse extends \generic_protocol\BackwardMessage
{
    public  $dash_screen;       // DashScreenShopper
}

?>
