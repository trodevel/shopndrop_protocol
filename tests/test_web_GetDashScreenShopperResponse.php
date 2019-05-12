<?php

// $Revision: 11227 $ $Date:: 2019-05-10 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'web/GetDashScreenShopperResponse;20190522173000;4;121212;50668;0;0;20190522173000;3;2;232323;50667;0;0;20190522194500;1;1;343434;50672;0;0;20190522231000;2.5;1;454545;50667;0;0;20190523090000;1.5;1;5;565656;20190327202000;0;989898;50668;Germany;K=C3=B6ln;Eigelstein;1;=;141414;0;1;17.25;1.12;2;676767;20190522173000;0;979797;50667;Germany;K=C3=B6ln;Hohe=20Strasse;17;=;252525;0;3;23.39;2.5;1.5;787878;20190527202000;1;353535;50672;Germany;K=C3=B6ln;Antwerpener=20Strasse;25;=;363636;3;0;11.87;1.12;0.5;898989;20190529184500;1;767676;50674;Germany;K=C3=B6ln;Lindenstrasse;56;=;474747;2;0;20.15;2.02;1.2;909090;20190530193000;1;858585;50674;Germany;K=C3=B6ln;Roonnstrasse;29;=;585858;1;0;23.2;2.3;1.7;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
