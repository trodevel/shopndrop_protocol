#ifndef APG_SHOPNDROP_PROTOCOL__REQUEST_TYPE_PARSER_H
#define APG_SHOPNDROP_PROTOCOL__REQUEST_TYPE_PARSER_H

// includes
#include "enums.h"

namespace shopndrop_protocol
{

class RequestTypeParser
{
public:
    static request_type_e   to_request_type( const std::string & s );
};
} // namespace shopndrop_protocol

#endif // APG_SHOPNDROP_PROTOCOL__REQUEST_TYPE_PARSER_H
