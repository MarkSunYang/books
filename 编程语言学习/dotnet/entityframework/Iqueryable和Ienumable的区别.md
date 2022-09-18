
https://stackoverflow.com/questions/252785/what-is-the-difference-between-iqueryablet-and-ienumerablet


IEnumerable: IEnumerable is best suitable for working with in-memory collection (or local queries). IEnumerable doesn’t move between items, it is forward only collection.

IQueryable: IQueryable best suits for remote data source, like a database or web service (or remote queries). IQueryable is a very powerful feature that enables a variety of interesting deferred execution scenarios (like paging and composition based queries).