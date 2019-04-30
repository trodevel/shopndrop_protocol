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

// $Revision: 11006 $ $Date:: 2019-04-30 #$ $Author: serge $

namespace shopndrop_protocol;

require_once 'shopndrop_protocol.php';
require_once 'str_helper.php';              // to_string_GeoPosition
require_once __DIR__.'/../generic_protocol/str_helper.php';
require_once __DIR__.'/../basic_objects/str_helper.php';        // to_string_TimeWindow
require_once __DIR__.'/../php_snippets/epoch_to_date.php';      // epoch_to_date

function to_html_not_impl( & $obj )
{
    return get_html_table_header_elems( array( 'not implemented yet' ) );
}

/**************************************************
 * OBJECTS
 **************************************************/

function get_header_ProductItem()
{
    return get_html_table_header_elems( array( 'NAME', 'UNIT', 'PRICE', 'WEIGHT' ) );
}

function to_html_ProductItem_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->name,
        $obj->unit,
        $obj->price,
        $obj->weight ) );
}

function get_header_Ride()
{
    return get_html_table_header_elems( array( 'POSITION', 'DELIVERY TIME', 'MAX_WEIGHT' ) );
}

function to_html_Ride_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        to_string_GeoPosition( $obj->position ),
        \basic_objects\to_string_LocalTime( $obj->delivery_time ),
        $obj->max_weight ) );
}

function get_header_Order()
{
    return get_html_table_header_elems( array( 'DELIVERY TIME', 'SHOPPING LIST ID', 'SUM', 'STATUS' ) );
}

function to_html_Order_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        \basic_objects\to_string_LocalTime( $obj->delivery_time ),
        $obj->shopping_list_id,
        $obj->sum,
        to_string_order_status_e( $obj->status ) . " (" . $obj->status . ")" ) );
}

/**************************************************
 * RESPONSES
 **************************************************/

function to_html_AddRideResponse( & $obj )
{
    $res = get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_row_header( array( 'RIDE ID' ) ) .
        get_html_table_row_data( array( $obj->ride_id ) ) );

    return $res;
}

function to_html_CancelRideResponse( & $obj )
{
    $res = '<h3>CancelRideResponse</h3>';

    return $res;
}

function to_html_GetRideResponse( & $obj )
{
    $body = get_html_table_tr( to_html_Ride_tabledata( $obj->ride ) );

    $res = get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_tr( get_header_Ride() ) . $body );

    return $res;
}

function to_html_AddOrderResponse( & $obj )
{
    $res = get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_row_header( array( 'ORDER ID' ) ) .
        get_html_table_row_data( array( $obj->order_id ) ) );

    return $res;
}

function to_html_CancelOrderResponse( & $obj )
{
    $res = '<h3>CancelOrderResponse</h3>';

    return $res;
}

function to_html_GetPersonalUserInfoResponse( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_row_header( array( 'USER_ID', 'GENDER', 'LAST NAME', 'FIRST NAME',
                    'COMPANY', 'EMAIL', 'PHONE', 'TIMEZONE' ) ) .
            get_html_table_row_data( array( $obj->user_id, $obj->gender, $obj->last_name, $obj->first_name, $obj->company_name,
                    $obj->email, $obj->phone, $obj->timezone ) ) );
}

// *********************************************************

function to_html( $obj )
{
    $handler_map = array(
        'shopndrop_protocol\AddRideRequest'         => 'to_html_not_impl',
        'shopndrop_protocol\AddRideResponse'        => 'to_html_AddRideResponse',
        'shopndrop_protocol\CancelRideRequest'      => 'to_html_not_impl',
        'shopndrop_protocol\CancelRideResponse'     => 'to_html_CancelRideResponse',
        'shopndrop_protocol\GetRideRequest'         => 'to_html_not_impl',
        'shopndrop_protocol\GetRideResponse'        => 'to_html_GetRideResponse',
        'shopndrop_protocol\GetPersonalUserInfoRequest'     => 'to_html_not_impl',
        'shopndrop_protocol\GetPersonalUserInfoResponse'    => 'to_html_GetPersonalUserInfoResponse',
        'shopndrop_protocol\AddOrderRequest'        => 'to_html_not_impl',
        'shopndrop_protocol\AddOrderResponse'       => 'to_html_AddOrderResponse',
        'shopndrop_protocol\CancelOrderRequest'     => 'to_html_not_impl',
        'shopndrop_protocol\CancelOrderResponse'    => 'to_html_CancelOrderResponse',
    );

    $type = get_class ( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\shopndrop_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_html( $obj );
}

?>
