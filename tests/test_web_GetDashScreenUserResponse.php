<?php

// $Revision: 11291 $ $Date:: 2019-05-12 #$ $Author: serge $

require_once '../shopndrop_protocol_web.php';
require_once '../response_parser_web.php';
require_once '../html_helper_web.php';

{
    $resp  =
    'web/GetDashScreenUserResponse;20190522173000;4;121212;50668;0;0;20190522173000;3;Matthias=20Mayer;232323;50667;0;0;20190522194500;1;Lukas=20Himmelfarb;343434;50672;0;0;20190522231000;2.5;Jonas=20Peschka;454545;50667;0;0;20190523090000;1.5;Anke=20Rittermeyer;5;565656;20190327202000;0;989898;50668;Germany;K=C3=B6ln;Eigelstein;1;=;141414;0;1;17.25;Liam=20Hoffman;676767;20190522173000;0;979797;50667;Germany;K=C3=B6ln;Hohe=20Strasse;17;=;252525;0;3;17.25;Julian=20Koch;787878;20190527202000;1;353535;50672;Germany;K=C3=B6ln;Antwerpener=20Strasse;25;=;363636;3;0;17.25;Tim=20Bauer;898989;20190529184500;1;767676;50674;Germany;K=C3=B6ln;Lindenstrasse;56;=;474747;2;0;17.25;Elias=20Wolf;909090;20190530193000;1;858585;50674;Germany;K=C3=B6ln;Roonnstrasse;29;=;585858;1;0;17.25;Michael=20Schr=C3=B6der;';

    $parsed = \shopndrop_protocol\web\ResponseParser::parse( $resp );

    echo "parsed: " . \shopndrop_protocol\web\to_html( $parsed ) . "\n";
}

?>
