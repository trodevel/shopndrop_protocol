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

// $Revision: 11002 $ $Date:: 2019-04-30 #$ $Author: serge $

namespace shopndrop_protocol;

require_once 'shopndrop_protocol.php';

function to_string_GeoPosition( & $obj )
{
    $res = $obj->plz . " ( " . $obj->latitude . ", " . $obj->longitude . " )";

    return $res;
}

function to_string_order_status_e( $val )
{
    $map = array(
        order_status_e_CANCELLED                   => 'CANCELLED',
        order_status_e_WAITING_ACCEPTANCE          => 'WAITING_ACCEPTANCE',
        order_status_e_ACCEPTED_WAITING_DELIVERY   => 'ACCEPTED_WAITING_DELIVERY',
        order_status_e_DELIVERED_WAITING_FEEDBACK  => 'DELIVERED_WAITING_FEEDBACK',
        order_status_e_CLOSED_FEEDBACK_RECEIVED    => 'CLOSED_FEEDBACK_RECEIVED',
    );

    if( array_key_exists( $val, $map ) )
    {
        return $map[ $val ];
    }

    return "?";
}

?>
