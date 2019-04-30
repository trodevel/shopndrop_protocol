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

// $Revision: 11015 $ $Date:: 2019-04-30 #$ $Author: serge $

namespace shopndrop_protocol\web;

require_once __DIR__.'/../shopndrop_protocol/html_helper.php';

function to_html_not_impl( & $obj )
{
    return get_html_table_header_elems( array( 'not implemented yet' ) );
}

/**************************************************
 * OBJECTS
 **************************************************/

function get_header_ProductItemWithId()
{
    return get_html_table_header_elems( array( 'ID' ) ) . \shopndrop_protocol\get_header_ProductItem();
}

function to_html_ProductItemWithId_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->product_item_id ) ) . \shopndrop_protocol\to_html_ProductItem_tabledata( $obj->product_item );
}

function to_html_GetProductItemListResponse( & $obj )
{
//     var_dump( $obj );

    $res = '<h3>Product Item List (' . sizeof( $obj->product_items ) . ')</h3>';

    $num   = sizeof( $obj->product_items );

    $body = '';
    for( $i = 0; $i < $num; $i++ )
    {
        $body = $body . get_html_table_tr( to_html_ProductItemWithId_tabledata( $obj->product_items[$i] ) );
    }

    $res = $res. get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_tr( get_header_ProductItemWithId() ) . $body );

    return $res;
}

function get_header_OrderRequestInfo()
{
    return get_html_table_header_elems( array( 'ORDER ID', 'SUM', 'EARNING', 'WEIGHT', 'POSITION', 'ADDRESS' ) );
}

function to_html_OrderRequestInfo_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
            $obj->order_id,
            $obj->sum,
            $obj->earning,
            $obj->weight,
            \shopndrop_protocol\to_string_GeoPosition( $obj->position ),
            $obj->address,
            ) );
}

function to_html_GetRideOrderInfoResponse( & $obj )
{
    $res = '<h3>Ride Order Info (' . sizeof( $obj->rides ) . ')</h3>';

    $num   = sizeof( $obj->rides );

    $body = '';
    for( $i = 0; $i < $num; $i++ )
    {
        $body = $body . get_html_table_tr( to_html_OrderRequestInfo_tabledata( $obj->rides[$i] ) );
    }

    $res = $res. get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_tr( get_header_OrderRequestInfo() ) . $body );

    return $res;
}

function get_header_RideWithShopper()
{
    return get_html_table_header_elems( array( 'RIDE ID' ) ) .
        \shopndrop_protocol\get_header_Ride() .
        get_html_table_header_elems( array( 'SHOPPER NAME' ) );
}

function to_html_RideWithShopper_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->ride_id ) ) .
        \shopndrop_protocol\to_html_Ride_tabledata( $obj->ride ) .
        get_html_table_data_elems( array(
            $obj->shopper_name ) );
}

function get_header_RideWithRequests()
{
    return get_html_table_header_elems( array( 'RIDE ID' ) ) .
    \shopndrop_protocol\get_header_Ride() .
    get_html_table_header_elems( array( 'NUM REQUESTS' ) );
}

function to_html_RideWithRequests_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->ride_id ) ) .
        \shopndrop_protocol\to_html_Ride_tabledata( $obj->ride ) .
        get_html_table_data_elems( array(
            $obj->num_requests ) );
}

function get_header_AcceptedOrderUser()
{
    return get_html_table_header_elems( array( 'ORDER ID' ) ) .
    \shopndrop_protocol\get_header_Order() .
    get_html_table_header_elems( array( 'SHOPPER NAME' ) );
}

function to_html_AcceptedOrderUser_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->order_id ) ) .
        \shopndrop_protocol\to_html_Order_tabledata( $obj->order ) .
        get_html_table_data_elems( array(
            $obj->shopper_name ) );
}

function get_header_AcceptedOrderShopper()
{
    return get_html_table_header_elems( array( 'ORDER ID' ) ) .
        \shopndrop_protocol\get_header_Order() .
        get_html_table_header_elems( array( 'POSITION', 'ADDRESS', 'EARNING', 'WEIGHT' ) );
}

function to_html_AcceptedOrderShopper_tabledata( & $obj )
{
    return get_html_table_data_elems( array(
        $obj->order_id ) ) .
        \shopndrop_protocol\to_html_Order_tabledata( $obj->order ) .
        get_html_table_data_elems( array(
            \shopndrop_protocol\to_string_GeoPosition( $obj->position ),
            $obj->address,
            $obj->earning,
            $obj->weight
            ) );
}

function to_html_DashScreenUser( & $obj )
{
    $res = '<h3>Dash Screen User ( current time ' . \basic_objects\to_string_LocalTime( $obj->current_time ) . ' )</h3>';

    {
        $num   = sizeof( $obj->rides );

        $res = $res . '<h2>Offered Rides ( ' . $num . ' )</h2>';

        $body = '';
        for( $i = 0; $i < $num; $i++ )
        {
            $body = $body . get_html_table_tr( to_html_RideWithShopper_tabledata( $obj->rides[$i] ) );
        }

        $res = $res . get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
                get_html_table_tr( get_header_RideWithShopper() ) . $body );
    }

    {
        $num   = sizeof( $obj->orders );

        $res = $res . '<h2>My accepted orders ( ' . $num . ' )</h2>';

        $body = '';
        for( $i = 0; $i < $num; $i++ )
        {
            $body = $body . get_html_table_tr( to_html_AcceptedOrderUser_tabledata( $obj->orders[$i] ) );
        }

        $res = $res . get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_tr( get_header_AcceptedOrderUser() ) . $body );
    }

    return $res;
}

function to_html_GetDashScreenUserResponse( & $obj )
{
    $res = to_html_DashScreenUser( $obj->dash_screen );

    return $res;
}

function to_html_DashScreenShopper( & $obj )
{
    $res = '<h3>Dash Screen Shopper ( current time ' . \basic_objects\to_string_LocalTime( $obj->current_time ) . ' )</h3>';

    {
        $num   = sizeof( $obj->rides );

        $res = $res . '<h2>My Offered Rides and Shopping Requests( ' . $num . ' )</h2>';

        $body = '';
        for( $i = 0; $i < $num; $i++ )
        {
            $body = $body . get_html_table_tr( to_html_RideWithRequests_tabledata( $obj->rides[$i] ) );
        }

        $res = $res . get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_tr( get_header_RideWithRequests() ) . $body );
    }

    {
        $num   = sizeof( $obj->orders );

        $res = $res . '<h2>My accepted orders ( ' . $num . ' )</h2>';

        $body = '';
        for( $i = 0; $i < $num; $i++ )
        {
            $body = $body . get_html_table_tr( to_html_AcceptedOrderShopper_tabledata( $obj->orders[$i] ) );
        }

        $res = $res . get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_tr( get_header_AcceptedOrderShopper() ) . $body );
    }

    return $res;
}

function to_html_GetDashScreenShopperResponse( & $obj )
{
    $res = to_html_DashScreenShopper( $obj->dash_screen );

    return $res;
}

// *********************************************************

function to_html( $obj )
{
    $handler_map = array(
        'shopndrop_protocol\web\GetProductItemListRequest'      => 'to_html_not_impl',
        'shopndrop_protocol\web\GetProductItemListResponse'     => 'to_html_GetProductItemListResponse',
        'shopndrop_protocol\web\GetRideOrderInfoRequest'        => 'to_html_not_impl',
        'shopndrop_protocol\web\GetRideOrderInfoResponse'       => 'to_html_GetRideOrderInfoResponse',
        'shopndrop_protocol\web\GetDashScreenUserRequest'       => 'to_html_not_impl',
        'shopndrop_protocol\web\GetDashScreenUserResponse'      => 'to_html_GetDashScreenUserResponse',
        'shopndrop_protocol\web\GetDashScreenShopperRequest'    => 'to_html_not_impl',
        'shopndrop_protocol\web\GetDashScreenShopperResponse'   => 'to_html_GetDashScreenShopperResponse'
    );

    $type = get_class ( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\shopndrop_protocol\\web\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \shopndrop_protocol\to_html( $obj );
}

?>