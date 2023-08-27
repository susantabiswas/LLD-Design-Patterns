using System;
using System.Console;


//////////////////////////////////////////////////// WITHOUT DEPENDENCY INVERSION //////////////////////////////////////
namespace WithoutDependencyInversion {
    
    public class LowLevel {
        public void ImportantWork() {
            System.Console.WriteLine("Important work done by low level component...");
        }
    }

    public class HighLevel {
        public static void UseLowLevel(LowLevel lowLevelObject) {
            lowLevelObject.ImportantWork();
        }
    }


    public static class Program {
        static void Main(string[] args) {
            Console.WriteLine(HighLevel.UseLowLevel(new LowLevelImplementation1()));
        }
    }
}

//////////////////////////////////////////////////// WITH DEPENDENCY INVERSION //////////////////////////////////////
namespace WithDependencyInversion {
    
    // Abstraction for Low level component
    public interface ILowLevel {
        public void ImportantWork();
    }

    public class LowLevelImplementation1: ILowLevel {
        // This implements an abstract class instead of being a 
        // direct concrete class
        public void ImportantWork() {
            System.Console.WriteLine("Important work done by low level component 1...");
        }
    }
    
    public class LowLevelImplementation2: ILowLevel {
        // This implements an abstract class instead of being a 
        // direct concrete class
        public void ImportantWork() {
            Console.WriteLine("Important work done by low level component 2...");
        }
    }

    public static class HighLevel {
        // The High level class now is dependent on an abstract rather
        // than a concrete implementation
        public static void UseLowLevel(ILowLevel lowLevelObject) {
            lowLevelObject.ImportantWork();
        }
    }


    public static class Program {
        static void Main(string[] args) {
            // Since abstraction is used now, a different implementation
            // of low level class can be used with the high level component
            Console.WriteLine(HighLevel.UseLowLevel(new LowLevelImplementation1()));
            Console.WriteLine(HighLevel.UseLowLevel(new LowLevelImplementation2()));
        }
    }
}