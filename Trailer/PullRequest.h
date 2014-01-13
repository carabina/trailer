
#define kPullRequestSectionMine 0
#define kPullRequestSectionParticipated 1
#define kPullRequestSectionMerged 2
#define kPullRequestSectionAll 3

#define kPullRequestSectionNames @[@"Mine", @"Participated", @"Recently Merged", @"All Pull Requests"]

@interface PullRequest : DataItem

@property (nonatomic, retain) NSString * url;
@property (nonatomic, retain) NSNumber * number;
@property (nonatomic, retain) NSString * state;
@property (nonatomic, retain) NSString * title;
@property (nonatomic, retain) NSString * body;
@property (nonatomic, retain) NSString * issueCommentLink;
@property (nonatomic, retain) NSString * reviewCommentLink;
@property (nonatomic, retain) NSDate * updatedAt;
@property (nonatomic, retain) NSNumber * serverId;
@property (nonatomic, retain) NSNumber * postSyncAction;
@property (nonatomic, retain) NSString * webUrl;
@property (nonatomic, retain) NSNumber * userId;
@property (nonatomic, retain) NSString * userAvatarUrl;
@property (nonatomic, retain) NSString * userLogin;
@property (nonatomic, retain) NSDate * latestReadCommentDate;
@property (nonatomic, retain) NSNumber *repoId;
@property (nonatomic, retain) NSNumber *merged;

@property (nonatomic, retain) NSNumber *totalComments;
@property (nonatomic, retain) NSNumber *unreadComments;

@property (nonatomic, retain) NSNumber *sectionIndex;
@property (nonatomic, readonly) NSString *sectionName;

+ (PullRequest *)pullRequestWithInfo:(NSDictionary*)info moc:(NSManagedObjectContext *)moc;

+ (PullRequest *)pullRequestWithUrl:(NSString *)url moc:(NSManagedObjectContext *)moc;

+ (NSFetchRequest *)requestForPullRequestsWithFilter:(NSString *)filter;

+ (NSArray *)allMergedRequestsInMoc:(NSManagedObjectContext *)moc;

+ (NSUInteger)countUnmergedRequestsInMoc:(NSManagedObjectContext *)moc;

- (void)catchUpWithComments;

- (BOOL)isMine;

- (BOOL)commentedByMe;

- (void)postProcess;

@end
