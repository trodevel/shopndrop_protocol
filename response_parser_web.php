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

// $Revision: 10941 $ $Date:: 2019-04-27 #$ $Author: serge $

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

class ResponseParser extends \shopndrop_protocol\ResponseParser
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
        $func = '\\shopndrop_protocol\\web\\' . $func_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return \shopndrop_protocol\ResponseParser::parse_csv_array( $csv_arr );
}

}

?>
