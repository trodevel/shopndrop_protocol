<?php

namespace shopndrop_protocol;


// includes
require_once __DIR__.'/../basic_parser/object.php';
require_once __DIR__.'/../generic_protocol/protocol.php';

// includes for used modules
require_once __DIR__.'/../basic_objects/protocol.php';

// Enum ride_resolution_e
const ride_resolution_e__UNDEF                = 0;
const ride_resolution_e__EXPIRED_OR_COMPLETED = 1;
const ride_resolution_e__CANCELLED            = 2;

// Enum order_resolution_e
const order_resolution_e__UNDEF                = 0;
const order_resolution_e__DELIVERED            = 1;
const order_resolution_e__DECLINED_BY_SHOPPER  = 2;
const order_resolution_e__RIDE_CANCELLED       = 3;
const order_resolution_e__CANCELLED_BY_SHOPPER = 4;
const order_resolution_e__CANCELLED_BY_USER    = 5;

// Enum order_state_e
const order_state_e__UNDEF                = 0;
const order_state_e__IDLE_WAITING_ACCEPTANCE = 1;
const order_state_e__ACCEPTED_WAITING_DELIVERY = 2;
const order_state_e__DELIVERED_WAITING_FEEDBACK = 3;

// Enum gender_e
const gender_e__UNDEF                = 0;
const gender_e__MALE                 = 1;
const gender_e__FEMALE               = 2;

// Object
class ProductItem
{
    public $name                ; // type: string // size constrain: [1, +inf)
    public $unit                ; // type: string // size constrain: [1, +inf)
    public $price               ; // type: double // valid range: (0, +inf)
    public $weight              ; // type: double // valid range: (0, +inf)
};

// Object
class ShoppingItem
{
    public $product_item_id     ; // type: uint32_t // valid range: [1, +inf)
    public $amount              ; // type: uint32_t // valid range: [1, +inf)
};

// Object
class ShoppingList
{
    public $items               ; // type: array<ShoppingItem> // size constrain: [1, +inf)
};

// Object
class GeoPosition
{
    public $plz                 ; // type: uint32_t // valid range: [1, +inf)
    public $latitude            ; // type: double // valid range: [0, 0]
    public $longitude           ; // type: double // valid range: [0, 0]
};

// Object
class RideSummary
{
    public $position            ; // type: GeoPosition
    public $delivery_time       ; // type: basic_objects\LocalTime
    public $max_weight          ; // type: double // valid range: (0, +inf)
};

// Object
class Ride
{
    public $is_open             ; // type: bool
    public $summary             ; // type: RideSummary
    public $pending_order_ids   ; // type: array<uint32_t>
    public $accepted_order_id   ; // type: uint32_t
    public $resolution          ; // type: ride_resolution_e
};

// Object
class Address
{
    public $plz                 ; // type: uint32_t // valid range: [1, +inf)
    public $country             ; // type: string // size constrain: (0, +inf)
    public $city                ; // type: string // size constrain: (0, +inf)
    public $street              ; // type: string // size constrain: (0, +inf)
    public $house_number        ; // type: string // size constrain: (0, +inf)
    public $extra_address_line  ; // type: string
};

// Object
class Order
{
    public $is_open             ; // type: bool
    public $ride_id             ; // type: uint32_t // valid range: [1, +inf)
    public $delivery_address    ; // type: Address
    public $shopping_list_id    ; // type: uint32_t // valid range: [1, +inf)
    public $state               ; // type: order_state_e
    public $resolution          ; // type: order_resolution_e
};

// Base message
class Request extends \generic_protocol\Request
{
    function __construct()
    {
        parent::__construct();
    }
};

// Message
class AddRideRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1336774100;

    public $ride                ; // type: RideSummary
};

// Message
class AddRideResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3741428193;

    public $ride_id             ; // type: uint32_t // valid range: [1, +inf)
};

// Message
class CancelRideRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2605092588;

    public $ride_id             ; // type: uint32_t // valid range: [1, +inf)
};

// Message
class CancelRideResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 4158126716;
};

// Message
class GetRideRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1726083611;

    public $ride_id             ; // type: uint32_t // valid range: [1, +inf)
};

// Message
class GetRideResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3572710079;

    public $ride                ; // type: Ride
};

// Message
class AddOrderRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3850194728;

    public $ride_id             ; // type: uint32_t // valid range: [1, +inf)
    public $shopping_list       ; // type: ShoppingList
    public $delivery_address    ; // type: Address
};

// Message
class AddOrderResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1805698836;

    public $order_id            ; // type: uint32_t // valid range: [1, +inf)
};

// Message
class CancelOrderRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3450543285;

    public $order_id            ; // type: uint32_t // valid range: [1, +inf)
};

// Message
class CancelOrderResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3845586622;
};

// Message
class AcceptOrderRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1004951276;

    public $order_id            ; // type: uint32_t // valid range: [1, +inf)
};

// Message
class AcceptOrderResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 4151794340;
};

// Message
class DeclineOrderRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3690205937;

    public $order_id            ; // type: uint32_t // valid range: [1, +inf)
};

// Message
class DeclineOrderResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2492539961;
};

// Message
class MarkDeliveredOrderRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3659215545;

    public $order_id            ; // type: uint32_t // valid range: [1, +inf)
};

// Message
class MarkDeliveredOrderResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3969319611;
};

// Message
class RateShopperRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3246489651;

    public $order_id            ; // type: uint32_t // valid range: [1, +inf)
    public $stars               ; // type: uint32_t // valid range: [0, 5]
};

// Message
class RateShopperResponse extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3789681207;
};

// namespace_end shopndrop_protocol


?>

