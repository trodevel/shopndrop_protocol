<?php

// $Revision: 11174 $ $Date:: 2019-05-09 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'web/GetDashScreenShopperResponse;20190522173000;4;121212;50668;0;0;20190522173000;3;2;232323;50667;0;0;20190522194500;1;1;343434;50672;0;0;20190522231000;2.5;1;454545;50667;0;0;20190523090000;1.5;1;5;565656;0;20190327202000;141414;17.25;0;1;50668;0;0;Eigelstein=201;1.12;2;676767;0;20190522173000;252525;23.39;0;3;50667;0;0;Hohe=20Strasse=2017;2.5;1.5;787878;1;20190527202000;363636;11.87;3;0;50672;0;0;Antwerpener=20Strasse=2025;1.12;0.5;898989;1;20190529184500;474747;20.15;2;0;50674;0;0;Lindenstrasse=2056;2.02;1.2;909090;1;20190530193000;585858;23.2;1;0;50674;0;0;Roonnstrasse=2029;2.3;1.7;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
