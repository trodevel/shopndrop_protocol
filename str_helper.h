/*

String Helper. Provides to_string() function.

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

// $Revision: 10805 $ $Date:: 2019-04-07 #$ $Author: serge $

#include <string>
#include <sstream>

#include "enums.h"                  // request_type_e
#include "shopndrop_protocol.h"     // order_status_e

namespace shopndrop_protocol {

class StrHelper
{
public:
    static std::string to_string( const request_type_e l );
    static const std::string & to_string( const order_status_e l );
    static std::ostream & write( std::ostream & os, const Ride & l );
    static std::ostream & write( std::ostream & os, const AddRideRequest & l );
    static std::ostream & write( std::ostream & os, const CancelRideRequest & l );
    static std::ostream & write( std::ostream & os, const GetRideRequest & l );
    static std::ostream & write( std::ostream & os, const AddOrderRequest & l );
    static std::ostream & write( std::ostream & os, const CancelOrderRequest & l );
    static std::ostream & write( std::ostream & os, const GetPersonalUserInfoRequest & l );

    template<class T>
    static std::string to_string( const T & l )
    {
        std::ostringstream os;

        write( os, l );

        return os.str();
    }
};

} // namespace shopndrop_protocol