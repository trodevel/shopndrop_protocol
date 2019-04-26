<?php

/*

Response Parser.

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

// $Revision: 10937 $ $Date:: 2019-04-26 #$ $Author: serge $

namespace shopndrop_protocol;

require_once __DIR__.'/../php_snippets/convert_csv_to_array.php';   // convert_csv_to_array()
require_once __DIR__.'/../php_snippets/nonascii_hex_codec.php';     // \utils\nonascii_hex_codec\decode()
require_once __DIR__.'/../generic_protocol/response_parser.php';    // generic_protocol\create_parse_error()
require_once __DIR__.'/../basic_objects/parser.php';                // \basic_objects\parse_TimePoint24
require_once __DIR__.'/../basic_parser/parser.php';                 // \basic_parser\parse_VectorInt
require_once 'shopndrop_protocol.php';

function parse_ProductItem( & $csv_arr, & $offset )
{
    // 121212;Milch;Packung;1.09;1

    $res = new ProductItem;

    $res->name      = $csv_arr[ $offset++ ];
    $res->unit      = $csv_arr[ $offset++ ];
    $res->price     = floatval( $csv_arr[ $offset++ ] );
    $res->weigth    = floatval( $csv_arr[ $offset++ ] );

    return $res;
}

function parse_GeoPosition( & $csv_arr, & $offset )
{
    // 50667;0;0;

    $plz        = intval( $csv_arr[ $offset++ ] );
    $latitude   = floatval( $csv_arr[ $offset++ ] );
    $longitude  = floatval( $csv_arr[ $offset++ ] );

    $res = new GeoPosition( $plz, $latitude, $longitude );

    return $res;
}

function parse_Ride( & $csv_arr, & $offset )
{
    // 50668;0;0;20190522173000;3.5

    $position       = parse_GeoPosition( $csv_arr, $offset );
    $delivery_time  = \basic_objects\parse_LocalTime( $csv_arr, $offset );
    $max_weigth     = floatval( $csv_arr[ $offset++ ] );

    $res = new Ride( $position, $delivery_time, $max_weigth );

    return $res;
}

function parse_Address( & $csv_arr, & $offset )
{
    // 50668;Cologne;Breslau Platz;;Germany

    $res = new Address;

    $res->plz           = intval( $csv_arr[ $offset++ ] );
    $res->city          = $csv_arr[ $offset++ ];
    $res->street        = $csv_arr[ $offset++ ]
    $res->house_number  = $csv_arr[ $offset++ ]
    $res->extra_address_line    = $csv_arr[ $offset++ ]
    $res->country       = $csv_arr[ $offset++ ]

    return $res;
}

function parse_Order( & $csv_arr, & $offset )
{
    // 20190327202000;141414;17.25;4

    $res = new Order;

    $res->delivery_time     = \basic_objects\parse_LocalTime( $csv_arr, $offset );
    $res->shopping_list_id  = intval( $csv_arr[ $offset++ ] );
    $res->sum               = floatval( $csv_arr[ $offset++ ] );
    $res->status            = intval( $csv_arr[ $offset++ ] );

    return $res;
}

function parse_AddRideResponse( & $resp )
{
    // AddRideResponse;123;

    $offset = 1;

    $res = new AddRideResponse;

    $res->ride_id       = intval( $csv_arr[ $offset++ ] );

    return $res;
}

function parse_CancelRideResponse( & $resp )
{
    // CancelRideResponse;

    $res = new CancelRideResponse;

    return $res;
}

function parse_GetRideResponse( & $resp )
{
    // GetRideResponse;50668;0;0;20190522180000;2;

    $offset = 1;

    $res = new GetRideResponse;

    $res->ride  = parse_Ride( $csv_arr, $offset );

    return $res;
}

function parse_AddOrderResponse( & $resp )
{
    // AddOrderResponse;123;

    $offset = 1;

    $res = new AddOrderResponse;

    $res->orders_id     = intval( $csv_arr[ $offset++ ] );

    return $res;
}

function parse_CancelOrderResponse( & $resp )
{
    // CancelOrderResponse;

    $res = new CancelOrderResponse;

    return $res;
}

function parse_GetPersonalUserInfoResponse( & $resp )
{
    // GetPersonalUserInfoResponse;123;1;John;Doe;Yoyodine=20Corp.;john.doe@yoyodine.com;+491234567890;Europe/Berlin;

    $offset = 1;

    $res = new GetPersonalUserInfoResponse;

    $res->user_id       = intval( $csv_arr[ $offset++ ] );
    $res->gender        = intval( $csv_arr[ $offset++ ] );
    $res->first_name    = \utils\nonascii_hex_codec\decode( $csv_arr[ $offset++ ] );
    $res->last_name     = \utils\nonascii_hex_codec\decode( $csv_arr[ $offset++ ] );
    $res->company_name  = \utils\nonascii_hex_codec\decode( $csv_arr[ $offset++ ] );
    $res->email         = \utils\nonascii_hex_codec\decode( $csv_arr[ $offset++ ] );
    $res->phone         = \utils\nonascii_hex_codec\decode( $csv_arr[ $offset++ ] );
    $res->timezone      = $csv_arr[ $offset++ ];

    return $res;
}

class ResponseParser extends \generic_protocol\ResponseParser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return self::create_parse_error();

    $type = $csv_arr[0][0];

    $func_map = array(
        'AddRideResponse'               => 'parse_AddRideResponse',
        'CancelRideResponse'            => 'parse_CancelRideResponse',
        'GetRideResponse'               => 'parse_GetRideResponse',
        'AddOrderResponse'              => 'parse_AddOrderResponse',
        'CancelOrderResponse'           => 'parse_CancelOrderResponse',
        'GetPersonalUserInfoResponse'   => 'parse_GetPersonalUserInfoResponse',
        );

    if( array_key_exists( $type, $func_map ) )
    {
        $func = '\\shopndrop_protocol\\' . $func_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return \generic_protocol\ResponseParser::parse_csv_array( $csv_arr );
}

}

?>
