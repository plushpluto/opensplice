/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to TO_YEAR PrismTech
 *   Limited, its affiliated companies and licensors. All rights reserved.
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
 */
#include "ut_result.h"

os_int
ut_resultToReturnCode(
    ut_result result)
{
    os_int code = OS_RETCODE_ERROR;

    assert ((result & OS_RETCODE_ID_MASK) == OS_RETCODE_ID_UT_RESULT);

    switch (result) {
        case UT_RESULT_OK:
            code = OS_RETCODE_OK;
            break;
        case UT_RESULT_OUT_OF_MEMORY:
            code = OS_RETCODE_OUT_OF_RESOURCES;
            break;
        case UT_RESULT_WALK_ABORTED:
        case UT_RESULT_COUNT:
            code = OS_RETCODE_ERROR;
            break;
        case UT_RESULT_NOT_IMPLEMENTED:
            code = OS_RETCODE_UNSUPPORTED;
            break;
        case UT_RESULT_ILL_PARAM:
            code = OS_RETCODE_BAD_PARAMETER;
            break;
        default:
            assert (result == UT_RESULT_UNDEFINED);
            break;
    }

    return code;
}