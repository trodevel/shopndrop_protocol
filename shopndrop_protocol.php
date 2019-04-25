<?php

/*

Shopndrop Protocol messages.

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

// $Revision: 10899 $ $Date:: 2019-04-25 #$ $Author: serge $

namespace shopndrop_protocol;

require_once __DIR__.'/../basic_objects/basic_objects.php';         // \basic_objects\TimeWindow, \basic_objects\Weekdays
require_once __DIR__.'/../generic_protocol/generic_protocol.php';

class Request extends \generic_protocol\Request
{
    function __construct( $session_id )
    {
        parent::__construct( $session_id );
    }
}

/**************************************************
 * OBJECTS
 **************************************************/

class ProductItem
{
    public          $name;      // string
    public          $unit;      // string
    public          $price;     // double
    public          $weight;	// double
}

class ShoppingItem
{
    public          $product_item_id;  // id_t
    public          $amount;           // int

    public function to_generic_request()
    {
        $res = $this->product_item_id . "," . $this->amount;

        return $res;
    }
}

class ShoppingList
{
    public          $items; // array<ShoppingItem>

    public function to_generic_request()
    {

        $size   = sizeof( $obj );

        $body = '';
        for( $i = 0; $i < $size; $i++ )
        {
            $body = $body . $this->items[$i]->to_generic_request() . ",";
        }

        $res = array(
            "SHOPPING_LIST"    => $body );

        return \generic_protocol\assemble_request( $res );
    }
}

class GeoPosition
{
    public          $plz;       // int
    public          $latitude;  // double
    public          $longitude; // double

    function __construct( $plz, $latitude, $longitude )
    {
        $this->plz                  = $plz;
        $this->latitude             = $latitude;
        $this->longitude            = $longitude;
    }

    public static function withPlz( $plz )
    {
        $instance = new self( $plz, 0, 0 );

        return $instance;
    }

    public static function withPos( $latitude, $longitude )
    {
        $instance = new self( 0, $latitude, $longitude);

        return $instance;
    }

    public function to_generic_request()
    {
        $res = array(
            "PLZ"           => $this->plz,
            "LATITUDE"      => $this->latitude,
            "LONGITUDE"     => $this->longitude
            );

        return \generic_protocol\assemble_request( $res );
    }
}

class Ride
{
    public      $position;      // GeoPosition
    public      $delivery_time; // basic_objects::LocalTime
    public      $max_weight;    // double

    function __construct( $position, $delivery_time, $max_weight )
    {
        $this->position         = $position;
        $this->delivery_time    = $delivery_time;
        $this->max_weight       = $max_weight;
    }

    public function to_generic_request()
    {
        $res = array(
            "MAX_WEIGHT"    => $this->max_weight
            );

        return \generic_protocol\assemble_request( $res ) .
            $this->position->to_generic_request() .
            $this->delivery_time->to_generic_request( "DELIVERY_TIME" );
    }
}

const order_status_e_CANCELLED                   = 0;
const order_status_e_WAITING_ACCEPTANCE          = 1;
const order_status_e_ACCEPTED_WAITING_DELIVERY   = 2;
const order_status_e_DELIVERED_WAITING_FEEDBACK  = 3;
const order_status_e_CLOSED_FEEDBACK_RECEIVED    = 4;

const gender_e_UNDEF   = 0;
const gender_e_MALE    = 1;
const gender_e_FEMALE  = 2;

class Address
{
    public      $plz;       // int
    public      $city;      // string
    public      $street;    // string
    public      $house_number;  // string
    public      $extra_address_line;    // string
    public      $country;   // string
}

class Order
{
    public $delivery_time;      // basic_objects::LocalTime
    public  $shopping_list_id;  // id_t
    public  $sum;               // double
    public  $status;            // order_status_e
}

/**************************************************
 * WEB OBJECTS
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

class ShoppingListExt
{
    public  $items;             // array<ShoppingItemWithProduct>
}

class ShoppingListWithTotals
{
    public  $shopping_list;     // ShoppingListExt
    public  $price;             // double
    public  $weight;            // double
}

class RideWithShopper
{
    public  $ride_id;           // id_t
    public  $ride;              // Ride
    public  $shopper_name;      // string
}

class RideWithRequests
{
    public  $ride_id;           // id_t
    public  $ride;              // Ride
    public  $num_requests;      // int
}

class OrderRequestInfo
{
    public  $order_id;          // id_t
    public  $sum;               // double
    public  $earning;           // double
    public  $weight;            // double
    public  $position;          // GeoPosition
    public  $address;           // string
}

class AcceptedOrderUser
{
    public  $order_id;          // id_t
    public  $order;             // Order
    public  $shopper_name;      // string
}

class AcceptedOrderShopper
{
    public  $order_id;          // id_t
    public  $order;             // Order
    public  $position;          // GeoPosition
    public  $address;           // string
    public  $earning;           // double
    public  $weight;            // double
}

class DashScreenUser
{
    public  $current_time;      // basic_objects::LocalTime

    public  $rides;             // array<RideWithShopper>
    public  $orders;            // array<AcceptedOrderUser>
}

class DashScreenShopper
{
    public  $current_time;      // basic_objects::LocalTime

    public  $rides;             // array<RideWithRequests>
    public  $orders;            // array<AcceptedOrderShopper>
}

/**************************************************
 * REQUESTS
 **************************************************/

class AddRideRequest extends Request
{
    public $ride;   // Ride

    function __construct( $session_id, $ride )
    {
        parent::__construct( $session_id );

        $this->ride             = $ride;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "AddRideRequest"
            );

        return \generic_protocol\assemble_request( $res ) .
            $this->ride->to_generic_request() .
            parent::to_generic_request();
    }
}

class AddRideResponse extends \generic_protocol\BackwardMessage
{
    public        $ride_id;     // id_t
}

class CancelRideRequest extends Request
{
    public $ride_id;   // id_t

    function __construct( $session_id, $ride_id )
    {
        parent::__construct( $session_id );

        $this->ride_id          = $ride_id;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "CancelRideRequest",
            "RIDE_ID"   => $this->ride_id
            );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
}

class CancelRideResponse extends \generic_protocol\BackwardMessage
{
}

class GetRideRequest extends Request
{
    public $ride_id;   // id_t

    function __construct( $session_id, $ride_id )
    {
        parent::__construct( $session_id );

        $this->ride_id          = $ride_id;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "GetRideRequest",
            "RIDE_ID"   => $this->ride_id
            );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
}

class GetRideResponse extends \generic_protocol\BackwardMessage
{
    public $ride;   // Ride
}

class AddOrderRequest extends Request
{
    public $ride_id;        // id_t
    public $shopping_list;  // ShoppingList

    function __construct( $session_id, $ride_id, $shopping_list )
    {
        parent::__construct( $session_id );

        $this->ride_id          = $ride_id;
        $this->shopping_list    = $shopping_list;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "AddOrderRequest",
            "RIDE_ID"   => $this->ride_id
            );

        return \generic_protocol\assemble_request( $res ) .
            $this->shopping_list->to_generic_request() .
            parent::to_generic_request();
    }
}

class AddOrderResponse extends \generic_protocol\BackwardMessage
{
    public $order_id;   // id_t
}

class CancelOrderRequest extends Request
{
    public $order_id;   // id_t

    function __construct( $session_id, $order_id )
    {
        parent::__construct( $session_id );

        $this->order_id     = $order_id;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "CancelOrderRequest",
            "ORDER_ID"  => $this->order_id
            );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
}

class CancelOrderResponse extends \generic_protocol\BackwardMessage
{
}

/**************************************************
 * WEB REQUESTS
 **************************************************/

class GetProductItemListRequest extends Request
{
    function __construct( $session_id )
    {
        parent::__construct( $session_id );
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "web\GetProductItemListRequest",
        );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
}

class GetProductItemListResponse extends \generic_protocol\BackwardMessage
{
    public  $product_items;     // array<ProductItemWithId>
}

class GetRideOrderInfoRequest extends Request
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
            "CMD"       => "web\GetRideOrderInfoRequest",
            "RIDE_ID"   => $this->ride_id
        );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
}

class GetRideOrderInfoResponse extends \generic_protocol\BackwardMessage
{
    public  $rides;             // array<OrderRequestInfo>
}

class GetDashScreenUserRequest extends Request
{
    public  $user_id;           // id_t

    function __construct( $session_id, $user_id )
    {
        parent::__construct( $session_id );

        $this->user_id      = $user_id;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "web\GetDashScreenUserRequest",
            "USER_ID"   => $this->user_id
        );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
}

class GetDashScreenUserResponse extends \generic_protocol\BackwardMessage
{
    public  $dash_screen;       // DashScreenUser
}

class GetDashScreenShopperRequest extends Request
{
    public  $user_id;           // id_t

    function __construct( $session_id, $user_id )
    {
        parent::__construct( $session_id );

        $this->user_id      = $user_id;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "web\GetDashScreenShopperRequest",
            "USER_ID"   => $this->user_id
        );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
}

class GetDashScreenShopperResponse extends \generic_protocol\BackwardMessage
{
    public  $dash_screen;       // DashScreenShopper
}

?>
