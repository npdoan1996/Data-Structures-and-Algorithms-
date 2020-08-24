import java.lang.reflect.Array;
import java.lang.Math;

// Implements the Map ADT using a hash table with separate chaining.
public class HashSet<T> {
    private class Entry {
        public T mKey;
        public boolean mIsNil;

        public Entry(T key, boolean nilStatus){
            mKey = key; 
            mIsNil = nilStatus;
        }

    }

    private Entry[] mTable;
    private int mCount; // the number of elements in the set, i.e., "n"

    // Constructs a hashset with the given size.
   public HashSet(int tableSize) {
      int powerOfTwo = -1; 
      do { 
          tableSize /= 2; 
          powerOfTwo++; 
      } while (tableSize >= 1);
      tableSize = 2<<powerOfTwo;

      mTable = (Entry[])Array.newInstance(Entry.class, tableSize); 
      this.mCount = 0;
   }

    public int probing(int i){ 
        return (i*i + i)/2;
    }
    
    public double loadFactor(){ 
        return mCount / mTable.length;
    }

    public int count(){ 
        return mCount;
    }

    public void add(T key) {
        if (loadFactor() > 0.8){ 
            Entry[] newTable;
            newTable = (Entry[])Array.newInstance(Entry.class, mTable.length*2); 
            for (int i = 0; i < mTable.length; i++){ 
                if (mTable[i] != null && mTable[i].mIsNil == false){ 
                    Entry newEntry = new Entry(mTable[i].mKey, mTable[i].mIsNil);
                    int hashCode = Math.abs(mTable[i].mKey.hashCode());
                    int probIndex = 0; 
                    int position = hashCode + probing(probIndex);
                    position %= newTable.length;
                    do { 
                        if (newTable[position] == null){ 
                            newTable[position] = newEntry;
                            break;
                        }
                        probIndex++; 
                        position = hashCode + probing(probIndex);
                        position %= newTable.length;
                    } while (true);
                }
            }
            mTable = newTable;
        }
        // Every object in Java has a .hashCode() function that computes a h(k)
        // value for that object. Use that function for your hash table index
        // calculations. Note that in Java, .hashCode() can be negative!!! --> use absolute value.
        Entry newEntry = new Entry(key, false);

        int hashCode = Math.abs(key.hashCode());
        int probIndex = 0; 
        int position = hashCode + probing(probIndex); 
        position %= mTable.length;
        while (!(mTable[position] != null && mTable[position].mKey.equals(key))) { 
            if (mTable[position] == null){ 
                mTable[position] = newEntry;
                mCount++;
                break;
            }else if (mTable[position] != null && mTable[position].mIsNil == true){ 
                mTable[position] = newEntry;
                mCount++;
                break;
            } 
            probIndex++;
            position = hashCode + probing(probIndex);
            position %= mTable.length;
        }
        
    }

    // Returns true if the given key is present in the set.
    public boolean find(T key) {

        int hashCode = Math.abs(key.hashCode());
        int probIndex = 0; 
        int position = hashCode + probing(probIndex);
        position %= mTable.length;
        while (mTable[position] != null){ 
            if (mTable[position] != null && mTable[position].mIsNil == true){
                continue;
            }
            if (mTable[position] != null && mTable[position].mKey.equals(key)){ 
                return true;
            }
            if (probIndex >= mTable.length){
                return false;
            }
            probIndex++; 
            position = hashCode + probing(probIndex);
            position %= mTable.length;
        }
        return false;
    }

    // Removes the given key from the set.
    public void remove(T key) {

        int hashCode = Math.abs(key.hashCode());
        int probIndex = 0; 
        int position = hashCode + probing(probIndex);
        position %= mTable.length;
        while (mTable[position] != null) { 
            if (mTable[position].mIsNil == true){ 
                continue;
            }
            if (mTable[position].mKey.equals(key)){ 
                mTable[position].mKey = null; 
                mTable[position].mIsNil = true;
                mCount--;
            }
            if (probIndex >= mTable.length){
                break;
            }
            probIndex++; 
            position = hashCode + probing(probIndex);
            position %= mTable.length;
        } 
    }

    public void print(){ 
        for (int i = 0; i < mTable.length; i++){ 
            if (mTable[i] != null)
               System.out.println(mTable[i].mKey);
        }
    }

}