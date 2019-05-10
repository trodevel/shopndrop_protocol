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

// $Revision: 11240 $ $Date:: 2019-05-11 #$ $Author: serge $

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

    function __construct( $product_item_id, $amount )
    {
        $this->product_item_id  = $product_item_id;
        $this->amount           = $amount;
    }

    public function to_generic_request()
    {
        $res = $this->product_item_id . "," . $this->amount;

        return $res;
    }
}

class ShoppingList
{
    public          $items; // array<ShoppingItem>

    function __construct( $items )
    {
        $this->items    = $items;
    }

    public function to_generic_request()
    {
        $size   = sizeof( $this->items );

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

const order_resolution_e_UNDEF                  = 0;
const order_resolution_e_DELIVERED              = 1;
const order_resolution_e_DECLINED_BY_SHOPPER    = 2;
const order_resolution_e_RIDE_CANCELLED         = 3;
const order_resolution_e_CANCELLED_BY_SHOPPER   = 4;
const order_resolution_e_CANCELLED_BY_USER      = 5;


const order_state_e_UNDEF                       = 0;
const order_state_e_IDLE_WAITING_ACCEPTANCE     = 1;
const order_state_e_ACCEPTED_WAITING_DELIVERY   = 2;
const order_state_e_DELIVERED_WAITING_FEEDBACK  = 3;

const gender_e_UNDEF   = 0;
const gender_e_MALE    = 1;
const gender_e_FEMALE  = 2;

class Address
{
    public      $plz;       // int
    public      $country;   // string
    public      $city;      // string
    public      $street;    // string
    public      $house_number;  // string
    public      $extra_address_line;    // string

    function __construct( $plz, $country, $city, $street, $house_number, $extra_address_line )
    {
        $this->plz      = $plz;
        $this->country  = $country;
        $this->city     = $city;
        $this->street   = $street;
        $this->house_number = $house_number;
        $this->extra_address_line   = $extra_address_line;
    }

    public function to_generic_request()
    {
        $res = array(
            "PLZ"       => $this->plz,
            "COUNTRY:X" => str2hex( $this->country ),
            "CITY:X"    => str2hex( $this->city ),
            "STREET:X"  => str2hex( $this->street ),
            "HOUSE_NUMBER:X" => str2hex( $this->house_number ),
            "EAL:X"     => str2hex( $this->extra_address_line )
        );

        return \generic_protocol\assemble_request( $res );
    }

}

class Order
{
    public  $is_open;           // bool
    public  $delivery_time;     // basic_objects::LocalTime
    public  $delivery_address;  // Address
    public  $shopping_list_id;  // id_t
    public  $state;             // order_state_e
    public  $resolution;        // order_resolution_e
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
    public $delivery_address;   // Address

    function __construct( $session_id, $ride_id, $shopping_list, $delivery_address )
    {
        parent::__construct( $session_id );

        $this->ride_id          = $ride_id;
        $this->shopping_list    = $shopping_list;
        $this->delivery_address = $delivery_address;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "AddOrderRequest",
            "RIDE_ID"   => $this->ride_id
            );

        return \generic_protocol\assemble_request( $res ) .
            $this->shopping_list->to_generic_request() .
            $this->delivery_address->to_generic_request() .
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

class GetPersonalUserInfoRequest extends Request
{
    public $user_id;        // id_t

    function __construct( $session_id, $user_id )
    {
        parent::__construct( $session_id );

        $this->user_id      = $user_id;
    }

    public function to_generic_request()
    {
        $res = array(
            "CMD"       => "GetPersonalUserInfoRequest",
            "USER_ID"   => $this->user_id
        );

        return \generic_protocol\assemble_request( $res ) .
            parent::to_generic_request();
    }
};

class GetPersonalUserInfoResponse extends \generic_protocol\BackwardMessage
{
    public $user_id;        // id_t
    public $gender;         // gender_e
    public $first_name;     // string
    public $last_name;      // string
    public $company_name;   // string
    public $email;          // string
    public $phone;          // string
    public $timezone;       // string
};

?>
