# **Известные недостатки и сомнения по решению**

1. `EventLog` and `Game` classes are tightly coupled. For now it didn't seem as a big problem to me, as the project is small, but as it grows I believe this will prove to be a problem. One way to solve it might be making Game class `IObservable`.
2. `Board` holds all `Unit`s, and it holds the positions of each `Unit`, but `Unit`s don't know their position on the `Board`. To know their position, they query the `Board`. From the other side, if the `Unit` also has it's position, this will create multiple sources of truth (which one is the Unit's position - the one in the class or the one in Board?), and in this case we will need to remember and update both of them always to keep them syncronized (when one changes, the other must also be changed).
3. As the project grows, it might be sensible to separate some of the `Board`'s implementation to separate classes, for example `UnitLookup` and `PathFinder`.
4. Currently there is no exception handling done. An exception will go all the way out of main function. Instead, the program should shut down gracefully.
5. `Stats` class holds all the possible types of stats, so every `Unit` has all of them, just some are unset. Instead, it might be better for every stat to have it's own struct type, and each `Unit` will have only the stats it needs. For example, `Swordsman` will have data members `Health` and `Agility`.
6. For now, `Board` only has `ground` grid, but later, when we add `Crow` and `Mine` units, `Board` can be updated to either:
    - hold also `air` and `underground` grids
    - or rename `ground` to something like `unitsMap`, and add Z-coordinate, and it's size can be `3*W*H`, and we can have constant indexes for air, ground, and underground. Then accessing `(x, y)` corrdinate in air will be something like: `unitsMap[Layer::Air][x][y]`
7. If the program is fed an ill-formed file, it will throw and terminate.
8. The program's output is close to, but not identical with, the provided hardcoded output. There must be a small logical issue in the implementation.
