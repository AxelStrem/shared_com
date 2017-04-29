# shared_com  

`shared_com` smart pointer is intended to behave as close to `shared_ptr` as possible.  

It manages both COM reference counting and `QueryInterface` calls:

    {
      shared_com<Interface1> a = pInterface1;
      shared_com<Interface1> b = a; // AddRef() called
      shared_com<Interface2> c = a; // QueryInterface() called
      shared_com<Interface2> d = pInterface1_2; // QueryInterface() called
                                                // extra reference is released - source can be thrown away
      shared_com<IUnknown>   e = a; // Convertible interface - no need for QueryInterface(), AddRef() called 

      shared_com<Interface3> f;    // nullptr-initialized
      Interface3Factory(args, &f); // out parameter
    }  // all COM objects are released
