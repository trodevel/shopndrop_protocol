#ifndef APG_SHOPNDROP__PROTOCOL_H
#define APG_SHOPNDROP__PROTOCOL_H

// system includes
#include <vector>
#include <map>

// includes
#include "basic_parser/object.h"
#include "generic_protocol/protocol.h"

// includes for used modules
#include "basic_objects/protocol.h"

namespace shopndrop_protocol
{

// Enum
enum class ride_resolution_e
{
    UNDEF                = 0,
    EXPIRED_OR_COMPLETED = 1,
    CANCELLED            = 2,
};

// Enum
enum class order_resolution_e
{
    UNDEF                = 0,
    DELIVERED            = 1,
    DECLINED_BY_SHOPPER  = 2,
    RIDE_CANCELLED       = 3,
    CANCELLED_BY_SHOPPER = 4,
    CANCELLED_BY_USER    = 5,
};

// Enum
enum class order_state_e
{
    UNDEF                = 0,
    IDLE_WAITING_ACCEPTANCE = 1,
    ACCEPTED_WAITING_DELIVERY = 2,
    DELIVERED_WAITING_FEEDBACK = 3,
};

// Enum
enum class gender_e
{
    UNDEF                = 0,
    MALE                 = 1,
    FEMALE               = 2,
};

// Object
struct ProductItem
{
    std::string          name      ; // size constrain: [1, +inf)
    std::string          unit      ; // size constrain: [1, +inf)
    double               price     ; // valid range: (0, +inf)
    double               weight    ; // valid range: (0, +inf)
};

// Object
struct ShoppingItem
{
    uint32_t             product_item_id; // valid range: [1, +inf)
    uint32_t             amount    ; // valid range: [1, +inf)
};

// Object
struct ShoppingList
{
    std::vector<ShoppingItem> items     ; // size constrain: [1, +inf)
};

// Object
struct GeoPosition
{
    uint32_t             plz       ; // valid range: [1, +inf)
    double               latitude  ; // valid range: [0, 0]
    double               longitude ; // valid range: [0, 0]
};

// Object
struct RideSummary
{
    GeoPosition          position  ;
    basic_objects::LocalTime delivery_time;
    double               max_weight; // valid range: (0, +inf)
};

// Object
struct Ride
{
    bool                 is_open   ;
    RideSummary          summary   ;
    std::vector<uint32_t> pending_order_ids;
    uint32_t             accepted_order_id;
    ride_resolution_e    resolution;
};

// Object
struct Address
{
    uint32_t             plz       ; // valid range: [1, +inf)
    std::string          country   ; // size constrain: (0, +inf)
    std::string          city      ; // size constrain: (0, +inf)
    std::string          street    ; // size constrain: (0, +inf)
    std::string          house_number; // size constrain: (0, +inf)
    std::string          extra_address_line;
};

// Object
struct Order
{
    bool                 is_open   ;
    uint32_t             ride_id   ; // valid range: [1, +inf)
    Address              delivery_address;
    uint32_t             shopping_list_id; // valid range: [1, +inf)
    order_state_e        state     ;
    order_resolution_e   resolution;
};

// Base message
struct Request: public generic_protocol::Request
{
};

// Message
struct AddRideRequest: public Request
{
    enum
    {
        message_id = 2431248626
    };

    RideSummary          ride      ;
};

// Message
struct AddRideResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 231958649
    };

    uint32_t             ride_id   ; // valid range: [1, +inf)
};

// Message
struct CancelRideRequest: public Request
{
    enum
    {
        message_id = 3468537354
    };

    uint32_t             ride_id   ; // valid range: [1, +inf)
};

// Message
struct CancelRideResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 3203089937
    };
};

// Message
struct GetRideRequest: public Request
{
    enum
    {
        message_id = 3114637117
    };

    uint32_t             ride_id   ; // valid range: [1, +inf)
};

// Message
struct GetRideResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 102890279
    };

    Ride                 ride      ;
};

// Message
struct AddOrderRequest: public Request
{
    enum
    {
        message_id = 934252208
    };

    uint32_t             ride_id   ; // valid range: [1, +inf)
    ShoppingList         shopping_list;
    Address              delivery_address;
};

// Message
struct AddOrderResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 2510687907
    };

    uint32_t             order_id  ; // valid range: [1, +inf)
};

// Message
struct CancelOrderRequest: public Request
{
    enum
    {
        message_id = 2224529624
    };

    uint32_t             order_id  ; // valid range: [1, +inf)
};

// Message
struct CancelOrderResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 3598508007
    };
};

// Message
struct AcceptOrderRequest: public Request
{
    enum
    {
        message_id = 1926949505
    };

    uint32_t             order_id  ; // valid range: [1, +inf)
};

// Message
struct AcceptOrderResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 3292363773
    };
};

// Message
struct DeclineOrderRequest: public Request
{
    enum
    {
        message_id = 3904779176
    };

    uint32_t             order_id  ; // valid range: [1, +inf)
};

// Message
struct DeclineOrderResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 2249557832
    };
};

// Message
struct MarkDeliveredOrderRequest: public Request
{
    enum
    {
        message_id = 3753873058
    };

    uint32_t             order_id  ; // valid range: [1, +inf)
};

// Message
struct MarkDeliveredOrderResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 1727492075
    };
};

// Message
struct RateShopperRequest: public Request
{
    enum
    {
        message_id = 2294103134
    };

    uint32_t             order_id  ; // valid range: [1, +inf)
    uint32_t             stars     ; // valid range: [0, 5]
};

// Message
struct RateShopperResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 3534476142
    };
};

} // namespace shopndrop_protocol

#endif // APG_SHOPNDROP__PROTOCOL_H

