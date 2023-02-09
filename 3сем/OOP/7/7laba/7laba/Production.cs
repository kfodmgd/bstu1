using System;
using System.Collections.Generic;
using System.Text;

namespace _7laba
{
    public class Production
    {
        private int _prod_Id;
        public string OrgName { get; set; }

        public Production(int id, string orgname)
        {
            _prod_Id = id;
            OrgName = orgname;
        }
    }
}
