/*
 *                         Vortex OpenSplice
 *
 *   This software and documentation are Copyright 2006 to TO_YEAR ADLINK
 *   Technology Limited, its affiliated companies and licensors. All rights
 *   reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */
#ifndef SACPP_EXCEPTION_H
#define SACPP_EXCEPTION_H

#include "sacpp_dds_basic_types.h"
#include "cpp_dcps_if.h"

class OS_API DDS::Exception
{
   public:

      Exception () {};
      virtual ~Exception () {};

      static DDS::Exception* _downcast (DDS::Exception * e);
      static const DDS::Exception* _downcast (const DDS::Exception * e);

      virtual const char * _name () const = 0;
      virtual const char * _rep_id () const = 0;
      virtual void _raise () const = 0;
      virtual DDS::Exception_ptr _clone () const = 0;

      virtual DDS::UserException * _as_user ();
      virtual DDS::SystemException * _as_system ();
};

#undef OS_API
#endif
