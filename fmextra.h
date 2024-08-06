/*

Version: MPL 1.1

The contents of this file are subject to the Mozilla Public License Version 
1.1 the "License"; you may not use this file except in compliance with 
the License. You may obtain a copy of the License at 
http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the
License.

Portions created by the Initial Developer are Copyright (c) 2022
the Initial Developer. All Rights Reserved.

*/

namespace flmgr
{
    namespace extra
    {
        template<int t_bitarraysize> class bitarray
        {
            private:
            int bitarraysize = t_bitarraysize;
            int value;
            public:
            bitarray()
            {
                if(!(0 < this->bitarraysize <= 32))
                {
                    this->bitarraysize = 32;
                }
                this->value = 0;
            }
            int get_size()
            {
                return this->bitarraysize;
            }
            void clear()
            {
                this->value = 0;
            }
            int get_at(int index)
            {
                if(index >= this->bitarraysize)
                {
                    throw (index);
                    return 0;
                }
                return this->value & (1 << index) ? 1 : 0;
            }
            int set_at(int index, int value)
            {
                if(value != 0 && value != 1)
                {
                    throw (value);
                    return 1;
                }
                if(!(0 <= index < 32))
                {
                    throw(index);
                    return 1;
                }
                if(index >= this->bitarraysize)
                {
                    throw (index);
                    return 0;
                }

                this->value = value ? (this->value | (1 << index)) : (this->value & ~(1 << index));
                return 0;
            }
        };
    }
}