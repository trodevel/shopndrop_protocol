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

// $Revision: 10887 $ $Date:: 2019-04-20 #$ $Author: serge $

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

    function __construct( $plz )
    {
        $this->plz                  = $plz;
        $this->latitude             = 0;
        $this->longitude            = 0;
    }

    function __construct( $latitude, $longitude )
    {
        $this->plz                  = 0;
        $this->latitude             = $latitude;
        $this->longitude            = $longitude;
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
            "PLZ"           => $this->plz,
            "LATITUDE"      => $this->latitude,
            "LONGITUDE"     => $this->longitude
            );

        return \generic_protocol\assemble_request( $res );
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

?>