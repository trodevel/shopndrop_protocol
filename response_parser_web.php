<?php

/*

Response Parser. Web.

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

// $Revision: 11014 $ $Date:: 2019-04-30 #$ $Author: serge $

namespace shopndrop_protocol\web;

require_once __DIR__.'/../shopndrop_protocol/response_parser.php';

function parse_ProductItemWithId( & $csv_arr, & $offset )
{
    // 121212;Milch;Packung;1.09;1

    $res = new ProductItemWithId;

    $res->product_item_id   = \basic_parser\parse_int( $csv_arr, $offset );
    $res->product_item      = \shopndrop_protocol\parse_ProductItem( $csv_arr, $offset );

    return $res;
}

function parse_ShoppingItemWithProduct( & $csv_arr, & $offset )
{
    // 121212;2;Milch;Packung;1.09;1

    $res = new ShoppingItemWithProduct;

    $res->shopping_item     = \shopndrop_protocol\parse_ShoppingItem( $csv_arr, $offset );
    $res->product_item      = \shopndrop_protocol\parse_ProductItem( $csv_arr, $offset );

    return $res;
}

function parse_ShoppingListWithProduct( & $csv_arr, & $offset )
{
    // 1;121212;2;Milch;Packung;1.09;1

    $res = new ShoppingListWithProduct;

    $size    = \basic_parser\parse_int( $csv_arr, $offset );

    //echo "size = $size\n";

    for( $i = 0; $i < $size; $i++ )
    {
        array_push( $res->items, parse_ShoppingItemWithProduct( $csv_arr, $offset ) );
    }

    return $res;
}

function parse_ShoppingListWithTotals( & $csv_arr, & $offset )
{
    // 1;121212;2;Milch;Packung;1.09;2;2.18;2;

    $res = new ShoppingListWithTotals;

    $res->shopping_list = parse_ShoppingListWithProduct( $csv_arr, $offset );
    $res->price         = \basic_parser\parse_float( $csv_arr, $offset );
    $res->weight        = \basic_parser\parse_float( $csv_arr, $offset );

    return $res;
}

function parse_RideWithShopper( & $csv_arr, & $offset )
{
    // 232323;50668;0;0;20190522173000;3.5;Johann=20Meyer;

    $res = new RideWithShopper;

    $res->ride_id       = \basic_parser\parse_int( $csv_arr, $offset );
    $res->ride          = \shopndrop_protocol\parse_Ride( $csv_arr, $offset );
    $res->shopper_name  = \basic_parser\parse_enc_string( $csv_arr, $offset );

    return $res;
}

function parse_RideWithRequests( & $csv_arr, & $offset )
{
    // 232323;50668;0;0;20190522173000;3.5;1;

    $res = new RideWithRequests;

    $res->ride_id       = \basic_parser\parse_int( $csv_arr, $offset );
    $res->ride          = \shopndrop_protocol\parse_Ride( $csv_arr, $offset );
    $res->num_requests  = \basic_parser\parse_int( $csv_arr, $offset );

    return $res;
}

function parse_OrderRequestInfo( & $csv_arr, & $offset )
{
    // 232323;2.18;.3;1.25;50668;0;0;20190522173000;Breslau=20Platz=201;

    $res = new OrderRequestInfo;

    $res->order_id      = \basic_parser\parse_int( $csv_arr, $offset );
    $res->sum           = \basic_parser\parse_float( $csv_arr, $offset );
    $res->earning       = \basic_parser\parse_float( $csv_arr, $offset );
    $res->weight        = \basic_parser\parse_float( $csv_arr, $offset );
    $res->position      = \shopndrop_protocol\parse_GeoPosition( $csv_arr, $offset );
    $res->address       = \basic_parser\parse_enc_string( $csv_arr, $offset );

    return $res;
}

function parse_AcceptedOrderUser( & $csv_arr, & $offset )
{
    // 232323;20190327202000;141414;17.25;4;Johann=20Meyer;

    $res = new AcceptedOrderUser;

    $res->order_id      = \basic_parser\parse_int( $csv_arr, $offset );
    $res->order         = \shopndrop_protocol\parse_Order( $csv_arr, $offset );
    $res->shopper_name  = \basic_parser\parse_enc_string( $csv_arr, $offset );

    return $res;
}

function parse_AcceptedOrderShopper( & $csv_arr, & $offset )
{
    // 232323;20190327202000;141414;17.25;4;50668;0;0;Breslau=20Platz=201;3.27;1.5;

    $res = new AcceptedOrderShopper;

    $res->order_id      = \basic_parser\parse_int( $csv_arr, $offset );
    $res->order         = \shopndrop_protocol\parse_Order( $csv_arr, $offset );
    $res->position      = \shopndrop_protocol\parse_GeoPosition( $csv_arr, $offset );
    $res->address       = \basic_parser\parse_enc_string( $csv_arr, $offset );
    $res->earning       = \basic_parser\parse_float( $csv_arr, $offset );
    $res->weight        = \basic_parser\parse_float( $csv_arr, $offset );

    return $res;
}

function parse_DashScreenUser( & $csv_arr, & $offset )
{
    // 20190327202000;...

    $res = new DashScreenUser;

    $res->current_time  = \basic_objects\parse_LocalTime( $csv_arr, $offset );

    {
        $size    = \basic_parser\parse_int( $csv_arr, $offset );

        //echo "size = $size\n";

        $res->rides = array();

        for( $i = 0; $i < $size; $i++ )
        {
            array_push( $res->rides, parse_RideWithShopper( $csv_arr, $offset ) );
        }
    }

    {
        $size    = \basic_parser\parse_int( $csv_arr, $offset );

        //echo "size = $size\n";

        $res->orders = array();

        for( $i = 0; $i < $size; $i++ )
        {
            array_push( $res->orders, parse_AcceptedOrderUser( $csv_arr, $offset ) );
        }
    }

    return $res;
}

function parse_DashScreenShopper( & $csv_arr, & $offset )
{
    // 20190327202000;...

    $res = new DashScreenShopper;

    $res->current_time  = \basic_objects\parse_LocalTime( $csv_arr, $offset );

    {
        $size    = \basic_parser\parse_int( $csv_arr, $offset );

        //echo "size = $size\n";

        $res->rides = array();

        for( $i = 0; $i < $size; $i++ )
        {
            array_push( $res->rides, parse_RideWithRequests( $csv_arr, $offset ) );
        }
    }

    {
        $size    = \basic_parser\parse_int( $csv_arr, $offset );

        //echo "size = $size\n";

        $res->orders = array();

        for( $i = 0; $i < $size; $i++ )
        {
            array_push( $res->orders, parse_AcceptedOrderShopper( $csv_arr, $offset ) );
        }
    }

    return $res;
}

function parse_GetProductItemListResponse( & $csv_arr )
{
    // GetProductItemListResponse;5;...

    $res = new GetProductItemListResponse;

    $offset = 1;

    $size    = \basic_parser\parse_int( $csv_arr, $offset );

    //echo "size = $size\n";

    $res->product_items = array();

    for( $i = 0; $i < $size; $i++ )
    {
        array_push( $res->product_items, parse_ProductItemWithId( $csv_arr, $offset ) );
    }

    return $res;
}

function parse_GetRideOrderInfoResponse( & $csv_arr )
{
    // GetRideOrderInfoResponse;5;...

    $res = new GetRideOrderInfoResponse;

    $offset = 1;

    $size    = \basic_parser\parse_int( $csv_arr, $offset );

    //echo "size = $size\n";

    $res->rides = array();

    for( $i = 0; $i < $size; $i++ )
    {
        array_push( $res->rides, parse_OrderRequestInfo( $csv_arr, $offset ) );
    }

    return $res;
}

function parse_GetDashScreenUserResponse( & $csv_arr )
{
    // GetDashScreenUserResponse;...

    $res = new GetDashScreenUserResponse;

    $offset = 1;

    $res->dash_screen   = parse_DashScreenUser( $csv_arr, $offset );

    return $res;
}

function parse_GetDashScreenShopperResponse( & $csv_arr )
{
    // GetDashScreenShopperResponse;...

    $res = new GetDashScreenShopperResponse;

    $offset = 1;

    $res->dash_screen   = parse_DashScreenShopper( $csv_arr, $offset );

    return $res;
}

class ResponseParser extends \shopndrop_protocol\ResponseParser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return self::create_parse_error();

    $type = $csv_arr[0][0];

    $func_map = array(
        'web/GetProductItemListResponse'    => 'parse_GetProductItemListResponse',
        'web/GetRideOrderInfoResponse'      => 'parse_GetRideOrderInfoResponse',
        'web/GetDashScreenUserResponse'     => 'parse_GetDashScreenUserResponse',
        'web/GetDashScreenShopperResponse'  => 'parse_GetDashScreenShopperResponse',
        );

    if( array_key_exists( $type, $func_map ) )
    {
        $func = '\\shopndrop_protocol\\web\\' . $func_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return \shopndrop_protocol\ResponseParser::parse_csv_array( $csv_arr );
}

}

?>
