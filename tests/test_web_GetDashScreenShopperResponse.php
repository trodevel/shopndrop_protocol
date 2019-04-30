<?php

// $Revision: 11012 $ $Date:: 2019-04-30 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'web/GetDashScreenShopperResponse;20190522173000;4;121212;50668;0;0;20190522173000;3;2;232323;50667;0;0;20190522194500;1;1;343434;50672;0;0;20190522231000;2.5;1;454545;50667;0;0;20190523090000;1.5;1;5;565656;20190327202000;141414;17.25;4;Eigelstein=201;50668;0;0;1.12;2;676767;20190522173000;252525;23.39;0;Hohe=20Strasse=2017;50667;0;0;2.5;1.5;787878;20190527202000;363636;11.87;3;Antwerpener=20Strasse=2025;50672;0;0;1.12;0.5;898989;20190529184500;474747;20.15;2;Lindenstrasse=2056;50674;0;0;2.02;1.2;909090;20190530193000;585858;23.2;1;Roonnstrasse=2029;50674;0;0;2.3;1.7;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
