// Specify the compatibility version we want
const LuceneVersion luceneVersion = LuceneVersion.LUCENE_48; 

//Open the Directory using a Lucene Directory class
string indexName = "example_index";
string indexPath = Path.Combine(Environment.CurrentDirectory, indexName);

using LuceneDirectory indexDir = FSDirectory.Open(indexPath);

//Create an analyzer to process the text 
Analyzer standardAnalyzer = new StandardAnalyzer(luceneVersion);


//Create an index writer
IndexWriterConfig indexConfig = new IndexWriterConfig(luceneVersion, standardAnalyzer);
indexConfig.OpenMode = OpenMode.CREATE;// create/overwrite index
IndexWriter writer = new IndexWriter(indexDir, indexConfig);


//Add three documents to the index
Document doc = new Document();
doc.Add(new TextField("titleTag", "The Apache Software Foundation - The world's largest open source foundation.", Field.Store.YES));
doc.Add(new StringField("domain", "www.apache.org/", Field.Store.YES));
writer.AddDocument(doc);

doc = new Document();
doc.Add(new TextField("title", "Powerful open source search library for .NET", Field.Store.YES));
doc.Add(new StringField("domain", "lucenenet.apache.org", Field.Store.YES));
writer.AddDocument(doc);

doc = new Document();
doc.Add(new TextField("title", "Unique gifts made by small businesses in North Carolina.", Field.Store.YES));
doc.Add(new StringField("domain", "www.giftoasis.com", Field.Store.YES));
writer.AddDocument(doc);

//Flush and commit the index data to the directory
writer.Commit();


using DirectoryReader reader = writer.GetReader(applyAllDeletes: true);
IndexSearcher searcher = new IndexSearcher(reader);

Query query = new TermQuery(new Term("domain", "lucenenet.apache.org"));
TopDocs topDocs = searcher.Search(query, n: 2);//indicate we want the first 2 results

int numMatchingDocs = topDocs.TotalHits;
Document resultDoc = searcher.Doc(topDocs.ScoreDocs[0].Doc);  //read back first doc from results (ie 0 offset)
string title = resultDoc.Get("title");