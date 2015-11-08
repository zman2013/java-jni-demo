class RocketMQProducer
{
private:
  string producerGroupName;

  string nameServerAddress;

public:
  RocketMQProducer(string producerGroupName, string nameServerAddress);

  void destroy();

  int send(Message message);

  int send(Message message, long timeout);
}

class RocketMQ[Orderly]Consumer
{
private:
  string consumerGroupName;

  string nameServerAddress;

public:
  RocketMQ[Orderly]Consumer(string consumerGroupName, string nameServerAddress);

  void setMode( enum Clustering/Broadcasting );

  void setConsumeType( enum FromLastConsume/FromTimeStamp );

  void setConsumeTimestamp( string timestamp );

  void connect( string topic, string tags );

  List<Message> pull( int batchSize, long timeout );

  List<Message> pull( int batchSize );

  Message pullOne();

  void ack( Message message );

  void commit( Message message );

  int sendMessageBack( Message message );

  void destroy();
}
