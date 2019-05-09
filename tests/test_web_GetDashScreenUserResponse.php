<?php

// $Revision: 11174 $ $Date:: 2019-05-09 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'web/GetDashScreenUserResponse;20190522173000;4;121212;50668;0;0;20190522173000;3;Matthias=20Mayer;232323;50667;0;0;20190522194500;1;Lukas=20Himmelfarb;343434;50672;0;0;20190522231000;2.5;Jonas=20Peschka;454545;50667;0;0;20190523090000;1.5;Anke=20Rittermeyer;5;565656;0;20190327202000;141414;17.25;0;1;Liam=20Hoffman;676767;0;20190522173000;252525;17.25;0;3;Julian=20Koch;787878;1;20190527202000;363636;17.25;3;0;Tim=20Bauer;898989;1;20190529184500;474747;17.25;2;0;Elias=20Wolf;909090;1;20190530193000;585858;17.25;1;0;Michael=20Schr=C3=B6der;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
