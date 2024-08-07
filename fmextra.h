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
    namespace mem_const
    {
        const int intbits = sizeof(int)*8;
    }
    namespace extra
    {
        template<int t_bitarraysize> class bitarray
        {
            private:
            int bitarraysize = t_bitarraysize;
            int bitarrayvalue[(t_bitarraysize/(flmgr::mem_const::intbits))+1];
            public:
            bitarray()
            {
                std::cout << "Created a bitarray with a size of " << sizeof(bitarrayvalue)/sizeof(int) << std::endl;
                if(!(0 < this->bitarraysize))
                {
                    this->bitarraysize = 32;
                }
                for(int i = 0; i < sizeof(bitarrayvalue)/sizeof(int); i++)
                {
                    bitarrayvalue[i] = 0;
                }
            }
            int get_size()
            {
                return this->bitarraysize;
            }
            void clear()
            {
                for(int i; i < sizeof(bitarrayvalue); i++)
                {
                    bitarrayvalue[i] = 0;
                }
            }
            int get_at(int index)
            {
                if(index >= this->bitarraysize)
                {
                    throw (index);
                    return 0;
                }
                return (bitarrayvalue[index/(flmgr::mem_const::intbits)]) & (1 << (index % (flmgr::mem_const::intbits))) ? 1 : 0;
            }
            int set_at(int index, int value)
            {
                if(value != 0 && value != 1)
                {
                    throw (value);
                    return 1;
                }
                if(!(0 <= index < this->bitarraysize))
                {
                    throw(index);
                    return 1;
                }

                int arridx = index/(flmgr::mem_const::intbits);
                int bitidx = index % (flmgr::mem_const::intbits);

                bitarrayvalue[arridx] = value ?
                    bitarrayvalue[arridx] | (1 << bitidx) :
                    bitarrayvalue[arridx] & ~(1 << bitidx);
                return 0;
            }
        };
    }
}