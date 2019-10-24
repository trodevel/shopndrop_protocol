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

// $Revision: 12248 $ $Date:: 2019-10-23 #$ $Author: serge $

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

function get_header_ShoppingItem()
{
    return get_html_table_header_elems( array( 'PRODUCT ITEM ID', 'AMOUNT' ) );
}

function to_html_ShoppingItem_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->product_item_id,
        $obj->amount ) );
}

function get_header_RideSummary()
{
    return get_html_table_header_elems( array( 'POSITION', 'DELIVERY TIME', 'MAX_WEIGHT' ) );
}

function to_html_RideSummary_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        to_string_GeoPosition( $obj->position ),
        \basic_objects\to_string_LocalTime( $obj->delivery_time ),
        $obj->max_weight ) );
}

function get_header_Ride()
{
    return get_html_table_header_elems( array( 'IS OPEN' ) ) .
        get_header_RideSummary() .
        get_html_table_header_elems( array( 'PENDING ORDER IDS', 'ACCEPTED ORDER ID', 'RESOLUTION' ) );

}

function to_html_Ride_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->is_open ? "Y" : "N" ) ) .
        to_html_RideSummary_tabledata( $obj->summary ) .
        get_html_table_data_elems( array(
            sizeof( $obj->pending_order_ids ) . ": " . \basic_objects\to_string_array( $obj->pending_order_ids ),
            $obj->accepted_order_id,
            to_string_ride_resolution_e( $obj->resolution ) . " (" . $obj->resolution . ")") );
}

function get_header_Address()
{
    return get_html_table_header_elems( array( 'PLZ', 'COUNTRY', 'CITY', 'STR', 'NO', 'EAL' ) );
}

function to_html_Address_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->plz,
        $obj->country,
        $obj->city,
        $obj->street,
        $obj->house_number,
        $obj->extra_address_line ) );
}

function get_header_Order()
{
    return get_html_table_header_elems( array( 'IS OPEN', 'RIDE ID' ) ) .
        get_header_Address() .
        get_html_table_header_elems( array( 'SHOPPING LIST ID', 'STATE', 'RESOLUTION' ) );
}

function to_html_Order_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->is_open ? "Y" : "N",
        $obj->ride_id ) ) .
        to_html_Address_tabledata( $obj->delivery_address ) .
        get_html_table_data_elems( array(
            $obj->shopping_list_id,
            to_string_order_state_e( $obj->state ) . " (" . $obj->state . ")",
            to_string_order_resolution_e( $obj->resolution ) . " (" . $obj->resolution . ")") );
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

function to_html_AcceptOrderResponse( & $obj )
{
    $res = '<h3>AcceptOrderResponse</h3>';

    return $res;
}

function to_html_DeclineOrderResponse( & $obj )
{
    $res = '<h3>DeclineOrderResponse</h3>';

    return $res;
}

function to_html_MarkDeliveredOrderResponse( & $obj )
{
    $res = '<h3>MarkDeliveredOrderResponse</h3>';

    return $res;
}

function to_html_RateShopperResponse( & $obj )
{
    $res = '<h3>RateShopperResponse</h3>';

    return $res;
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
        'shopndrop_protocol\AcceptOrderResponse'    => 'to_html_AcceptOrderResponse',
        'shopndrop_protocol\DeclineOrderResponse'   => 'to_html_DeclineOrderResponse',
        'shopndrop_protocol\MarkDeliveredOrderResponse'    => 'to_html_MarkDeliveredOrderResponse',
        'shopndrop_protocol\RateShopperResponse'    => 'to_html_RateShopperResponse',
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
